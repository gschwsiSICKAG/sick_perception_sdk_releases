import argparse
from prance import ResolvingParser
from tabulate import tabulate
from typing import List
import yaml

from objects import *
from parser import parse_path
from generator import generate_code

SUPPORTED_DEVICE_TYPES = ["picoScan100", "multiScan100", "multiScan200", "LRS4000"]


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


if __name__ == "__main__":
    # Fetch a few command line arguments
    parser = argparse.ArgumentParser(description="SICK Sensor SDK Open API Parser. Parses a SICK OpenAPI specification and generates C++ data objects.")
    parser.add_argument("filename", help="Path to the OpenAPI specification file (YAML or JSON)")
    parser.add_argument("-c", "--config", help="Path to the configuration file (YAML)")
    parser.add_argument("-d", "--device-type", help=f"Device type. Supported types are {', '.join(SUPPORTED_DEVICE_TYPES)}. This type determines the output directory and the C++ namespace.")
    parser.add_argument("--dry-run", action="store_true", help="If set, only the OpenAPI document will be parsed; no C++ files will be written.")
    args = parser.parse_args()

    # Make sure the caller gave us a valid device type.
    # We don't parse the device type from the OpenAPI document because there are too many different ways how the device type is specified.
    device_type = args.device_type if args.device_type else ""
    if device_type not in SUPPORTED_DEVICE_TYPES:
        raise Exception(f"No supported device type found. Supported types are {', '.join(SUPPORTED_DEVICE_TYPES)}")

    # Parse the specified OpenAPI document. This gives us a deeply nested dictionary.
    print(f"\n\nℹ️  Parsing OpenAPI specification from '{args.filename}'.")
    parser = ResolvingParser(args.filename)
    spec = parser.specification
    device_version = spec["info"]["version"]
    print(f"ℹ️  File contains specification for '{device_type}' version '{device_version}'.")

    # Get the list of blocked paths from the configuration file (if specified).
    # This list can be used to exclude API paths that we don't want to support.
    # Paths must be specified as they appear in the OpenAPI document, e.g. `/RebootDevice`.
    blocked_paths = get_blocked_paths(args.config)

    # Parse the paths and collect their data objects.
    # We don't collect all the methods because we're just interested in the payloads.
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

    # Print a summary
    headers = ["path", "has GET response", "has POST request", "has POST response", "is SOPAS method"]
    lines = []
    for endpoint in endpoint_descriptions:
        has_get_response = "🟢" if not endpoint.get is None and not endpoint.get.response_payload is None else "⚪"
        has_post_request = "🟢" if not endpoint.post is None and not endpoint.post.request_payload is None else "⚪"
        has_post_response = "🟢" if not endpoint.post is None and not endpoint.post.response_payload is None else "⚪"
        is_sopas_method = "🟠" if endpoint.is_sopas_method else "⚪"
        line = [endpoint.path, has_get_response, has_post_request, has_post_response, is_sopas_method]
        lines.append(line)
    print(tabulate(lines, headers, colalign=("left", "center", "center", "center", "center")))

    # Now that the payloads have been collected we can proceed to generating the C++ code.
    if not args.dry_run:
        generate_code(endpoint_descriptions, device_type, device_version)
    else:
        print(f"ℹ️  Skipping output generation because dry run was specified.")

    print(f"✅  All done. Have a nice day 😊")
