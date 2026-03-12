import argparse
from prance import ResolvingParser
from tabulate import tabulate
from typing import Any, Dict, List, Optional, Tuple
import yaml
import os
import glob

from objects import *
from parser import parse_path
from generator import generate_code
from table_generator import generate_configuration_table

SUPPORTED_DEVICE_TYPES = ["picoScan100", "multiScan100", "multiScan200", "LRS4000"]

# Map device names from file names to the canonical device type used in code generation
# This allows newer device models (e.g., picoScan150) to reuse the same API as their base model (picoScan100)
DEVICE_TYPE_MAPPING = {
    "picoScan150": "picoScan100",
}


def detect_device_type_from_filename(filename: str) -> str:
    """
    Try to detect the device type from the filename by matching against supported device types.
    Applies device type mapping to handle device variants (e.g., picoScan150 -> picoScan100).

    Args:
        filename: Path to the OpenAPI specification file

    Returns:
        Detected device type (after applying mapping)

    Raises:
        Exception: If no supported device type is found in the filename
    """
    # First check for mapped device types (e.g., picoScan150)
    for source_device, target_device in DEVICE_TYPE_MAPPING.items():
        if source_device in filename:
            print(f"ℹ️  Mapping device type '{source_device}' -> '{target_device}'")
            return target_device

    # Then check for standard supported device types
    for device_type in SUPPORTED_DEVICE_TYPES:
        if device_type in filename:
            return device_type

    raise Exception(f"Could not detect device type from filename '{filename}'. " f"Filename must contain one of: {', '.join(SUPPORTED_DEVICE_TYPES + list(DEVICE_TYPE_MAPPING.keys()))}")


def expand_file_arguments(paths: List[str]) -> List[str]:
    """
    Expand file arguments: if a path is a directory, find all .yml/.yaml files in it.

    Args:
        paths: List of file or directory paths

    Returns:
        List of file paths (directories expanded to their .yml/.yaml files)
    """
    expanded_files = []

    for path in paths:
        if os.path.isdir(path):
            # Find all .yml and .yaml files in the directory
            yml_files = glob.glob(os.path.join(path, "*.yml"))
            yaml_files = glob.glob(os.path.join(path, "*.yaml"))
            dir_files = sorted(yml_files + yaml_files)

            if not dir_files:
                print(f"⚠️  Warning: No .yml or .yaml files found in directory '{path}'")
            else:
                print(f"ℹ️  Found {len(dir_files)} YAML file(s) in directory '{path}'")
                expanded_files.extend(dir_files)
        elif os.path.isfile(path):
            expanded_files.append(path)
        else:
            raise Exception(f"Path '{path}' is neither a file nor a directory")

    return expanded_files


def get_blocked_paths(config_path) -> List[str]:
    """
    Try to read the list of blocked paths from the specified configuration file.
    If the file does not exist or cannot be parsed, an empty list is returned.
    """
    try:
        with open(config_path, "r") as f:
            config = yaml.safe_load(f)
        if not isinstance(config, dict):
            return []
        blocked_paths = config.get("blocked_paths")
        if isinstance(blocked_paths, list):
            return blocked_paths
        return []
    except Exception as e:
        print(f"❌  Cannot load configuration from '{config_path}': {e}")
        return []


def parse_openapi_file(filename: str, device_type: str, config_path: Optional[str] = None) -> Tuple[List[EndpointDescription], str]:
    """
    Parse a single OpenAPI specification file and return endpoint descriptions and device version.

    Args:
        filename: Path to the OpenAPI specification file
        device_type: Device type for this file
        config_path: Optional path to configuration file with blocked paths

    Returns:
        Tuple of (endpoint_descriptions, device_version)
    """
    # Get the list of blocked paths from the configuration file (if specified).
    blocked_paths = get_blocked_paths(config_path) if config_path else []

    # Parse the specified OpenAPI document. This gives us a deeply nested dictionary.
    print(f"ℹ️  Parsing OpenAPI specification from '{filename}' for device '{device_type}'.")
    parser = ResolvingParser(filename)
    spec: Dict[str, Any] = parser.specification  # type: ignore
    device_version = spec["info"]["version"]
    print(f"ℹ️  File contains specification for '{device_type}' version '{device_version}'.")

    # Parse the paths and collect their data objects.
    print(f"ℹ️  Parsing paths...")
    endpoint_descriptions: List[EndpointDescription] = []
    for path_name, path in spec["paths"].items():
        if path_name in blocked_paths:
            print(f"⚠️  Ignoring path '{path_name}' because it is in the blocked_paths list.")
            continue

        try:
            parse_path(path_name, path, endpoint_descriptions)
        except Exception as e:
            print(f"❌  Error parsing path '{path_name}': {e}")
            continue
    print(f"ℹ️  Found {len(endpoint_descriptions)} valid endpoint descriptions.")

    return endpoint_descriptions, device_version


if __name__ == "__main__":
    # Fetch a few command line arguments
    parser = argparse.ArgumentParser(description="SICK Sensor SDK Open API Parser. Parses a SICK OpenAPI specification and generates C++ data objects.")
    parser.add_argument(
        "filenames", nargs="+", help="Path(s) to the OpenAPI specification file(s) (YAML or JSON) or directory containing YAML files. Device types will be automatically detected from filenames."
    )
    parser.add_argument("-c", "--config", help="Path to the configuration file (YAML)")
    parser.add_argument(
        "-d",
        "--device-types",
        nargs="+",
        help=f"Device type(s) (optional). Supported types are {', '.join(SUPPORTED_DEVICE_TYPES)}. If not specified, device types will be automatically detected from filenames. If specified, must match the number of input files.",
    )
    parser.add_argument("--dry-run", action="store_true", help="If set, only the OpenAPI document will be parsed; no C++ files will be written.")
    args = parser.parse_args()

    # Expand directory arguments to file lists
    filenames = expand_file_arguments(args.filenames)

    if not filenames:
        raise Exception("No YAML files found to process")

    # Determine device types - either from arguments or by auto-detection
    if args.device_types:
        device_types = args.device_types
        # Validate that we have the same number of files and device types
        if len(filenames) != len(device_types):
            raise Exception(f"Number of files ({len(filenames)}) must match number of device types ({len(device_types)})")
    else:
        # Auto-detect device types from filenames
        print(f"ℹ️  Auto-detecting device types from filenames...")
        device_types = []
        for filename in filenames:
            device_type = detect_device_type_from_filename(filename)
            device_types.append(device_type)
            print(f"ℹ️  Detected '{device_type}' from '{filename}'")

    # Validate all device types
    for device_type in device_types:
        if device_type not in SUPPORTED_DEVICE_TYPES:
            raise Exception(f"Unsupported device type '{device_type}'. Supported types are {', '.join(SUPPORTED_DEVICE_TYPES)}")

    # Parse all OpenAPI files
    print(f"\n\nℹ️  Parsing {len(filenames)} OpenAPI specification file(s)...")
    all_endpoints = []
    for filename, device_type in zip(filenames, device_types):
        endpoint_descriptions, device_version = parse_openapi_file(filename, device_type, args.config)

        # Print a summary for this device
        print(f"\nℹ️  Summary for {device_type}:")
        headers = ["path", "has GET response", "has POST request", "has POST response", "is SOPAS method"]
        lines = []
        for endpoint in endpoint_descriptions:
            has_get_response = "🟢" if endpoint.get is not None and endpoint.get.response_payload is not None else "⚪"
            has_post_request = "🟢" if endpoint.post is not None and endpoint.post.request_payload is not None else "⚪"
            has_post_response = "🟢" if endpoint.post is not None and endpoint.post.response_payload is not None else "⚪"
            is_sopas_method = "🟠" if endpoint.is_sopas_method else "⚪"
            line = [endpoint.path, has_get_response, has_post_request, has_post_response, is_sopas_method]
            lines.append(line)
        print(tabulate(lines, headers, colalign=("left", "center", "center", "center", "center")))

        # Store for code generation
        all_endpoints.append((endpoint_descriptions, device_type, device_version))

    # Now that the payloads have been collected we can proceed to generating the C++ code and table.
    if not args.dry_run:
        # Generate C++ code for each device
        for endpoint_descriptions, device_type, device_version in all_endpoints:
            generate_code(endpoint_descriptions, device_type, device_version)

        # Generate configuration overview table
        device_data = {device_type: (endpoint_descriptions, device_version) for endpoint_descriptions, device_type, device_version in all_endpoints}
        generate_configuration_table(device_data)
    else:
        print(f"\nℹ️  Skipping output generation because dry run was specified.")

    print(f"\n✅  All done. Have a nice day 😊")
