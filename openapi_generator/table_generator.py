import os
from typing import Dict, List, Tuple
from tabulate import tabulate
import re

from objects import EndpointDescription


CONFIG_OVERVIEW_OUT_DIR = "doc"
CONFIG_OVERVIEW_FILENAME = "device_configuration_overview.md"
API_INCLUDE_BASE_PATH = "src/sensor_configuration/include/sick_perception_sdk/sensor_configuration/api"


def _normalize_tag(tag: str) -> str:
    """
    Normalize a tag for comparison across devices.

    Normalization process:
    1. Remove leading number and dash (e.g., "13 - ") if present
    2. Convert to UPPERCASE for case-insensitive comparison

    Examples:
    - "13 - Measurement data output" → "MEASUREMENT DATA OUTPUT"
    - "10 - Measurement Data Output" → "MEASUREMENT DATA OUTPUT"
    - "General" → "GENERAL"

    Args:
        tag: The original tag name

    Returns:
        Normalized tag for comparison
    """
    # Remove leading number and dash pattern (e.g., "13 - ")
    cleaned_tag = re.sub(r"^\d+\s*-\s*", "", tag)
    # Convert to uppercase
    return cleaned_tag.upper()


def generate_configuration_table(device_data: Dict[str, Tuple[List[EndpointDescription], str]]):
    """
    Generate a markdown table showing which configuration objects are supported by which devices.

    Args:
        device_data: Dictionary mapping device_type -> (endpoint_descriptions, device_version)
    """
    if not device_data:
        print("⚠️  No device data provided. Skipping table generation.")
        return

    out_file = os.path.abspath(os.path.join(CONFIG_OVERVIEW_OUT_DIR, CONFIG_OVERVIEW_FILENAME))
    print(f"ℹ️  Generating device configuration overview table in '{out_file}'...")

    # Collect all configuration objects across all devices
    config_objects = _collect_configuration_objects(device_data)

    if not config_objects:
        print("⚠️  No configuration objects found. Skipping table generation.")
        return

    # Analyze and report matching statistics
    _report_matching_statistics(device_data, config_objects)

    # Determine reference device and group by tags
    reference_device, tag_groups = _group_by_tags(device_data, config_objects)

    # Generate the markdown document
    with open(out_file, "w", encoding="utf-8") as f:
        _generate_header(f)
        _generate_table(f, device_data, config_objects, tag_groups)

    print(f"✅  Generated configuration overview with {len(config_objects)} configuration objects for {len(device_data)} devices.")


def _collect_configuration_objects(device_data: Dict[str, Tuple[List[EndpointDescription], str]]) -> List[str]:
    """
    Collect all unique configuration object names that have GET or POST operations.
    Uses exact name matching to identify the same configuration object across different devices.

    Filtering rules:
    - INCLUDE: Endpoints with GET operation (read access)
    - INCLUDE: Endpoints with POST operation (write access)
    - EXCLUDE: Endpoints without GET or POST operations

    Returns:
        Sorted list of unique configuration object names
    """
    config_objects = set()
    filtered_count = 0

    for device_type, (endpoints, _) in device_data.items():
        for endpoint in endpoints:
            # Filter: Only include endpoints that have GET or POST operations
            has_get = endpoint.get is not None
            has_post = endpoint.post is not None

            if has_get or has_post:
                # Match by exact class name to prevent duplicates across devices
                config_objects.add(endpoint.class_name)
            else:
                # Track filtered endpoints for reporting
                filtered_count += 1

    if filtered_count > 0:
        print(f"ℹ️  Filtered out {filtered_count} endpoints without GET or POST operations.")

    return sorted(config_objects)


def _report_matching_statistics(device_data: Dict[str, Tuple[List[EndpointDescription], str]], config_objects: List[str]):
    """
    Analyze and report statistics about configuration object matching across devices.

    Args:
        device_data: Dictionary mapping device_type -> (endpoint_descriptions, device_version)
        config_objects: List of all unique configuration object names
    """
    device_types = sorted(device_data.keys())

    # Build mapping of config object to list of devices that support it
    config_to_devices = {}
    for config_name in config_objects:
        supporting_devices = []
        for device_type, (endpoints, _) in device_data.items():
            # Find endpoint by exact name match
            endpoint = next((ep for ep in endpoints if ep.class_name == config_name), None)
            if endpoint and (endpoint.get is not None or endpoint.post is not None):
                supporting_devices.append(device_type)
        config_to_devices[config_name] = supporting_devices

    # Count shared vs device-specific configuration objects
    shared_objects = [name for name, devices in config_to_devices.items() if len(devices) > 1]
    device_specific_objects = [name for name, devices in config_to_devices.items() if len(devices) == 1]
    common_to_all = [name for name, devices in config_to_devices.items() if len(devices) == len(device_types)]

    print(f"ℹ️  Configuration object matching statistics:")
    print(f"    - Total unique configuration objects: {len(config_objects)}")
    print(f"    - Shared across multiple devices: {len(shared_objects)}")
    print(f"    - Common to all devices: {len(common_to_all)}")
    print(f"    - Device-specific: {len(device_specific_objects)}")

    # Report per-device totals
    print(f"ℹ️  Configuration objects per device:")
    for device_type in device_types:
        device_count = sum(1 for devices in config_to_devices.values() if device_type in devices)
        print(f"    - {device_type}: {device_count}")


def _group_by_tags(device_data: Dict[str, Tuple[List[EndpointDescription], str]], config_objects: List[str]) -> Tuple[str, Dict[str, List[str]]]:
    """
    Determine the reference device and group configuration objects by tags.
    The device with the highest number of tags determines the grouping structure.

    Grouping strategy:
    1. Configuration objects from reference device grouped by their tags (in order)
    2. Configuration objects from reference device without tags (separate group at end)
    3. Configuration objects from other devices not matching any in reference device (separate group at end)

    Tag normalization is applied to group similar tags across devices:
    - Tags with different formatting (e.g., different numbers or capitalization) are normalized
    - Normalized tags are used for comparison and grouping
    - Example: "13 - Measurement data output" and "10 - Measurement Data Output" group together

    Args:
        device_data: Dictionary mapping device_type -> (endpoint_descriptions, device_version)
        config_objects: List of all configuration object names

    Returns:
        Tuple of (reference_device_type, tag_groups)
        where tag_groups is a Dict mapping normalized_tag -> list of config_object names
    """
    # Find all unique tags across all devices and count them
    device_tags = {}
    for device_type, (endpoints, _) in device_data.items():
        tags_in_device = set()
        for endpoint in endpoints:
            if endpoint.tags:
                tags_in_device.update(endpoint.tags)
        device_tags[device_type] = tags_in_device

    # Determine reference device (device with most tags)
    reference_device = max(device_tags.keys(), key=lambda d: len(device_tags[d]))
    print(f"ℹ️  Using '{reference_device}' as reference device ({len(device_tags[reference_device])} tags).")

    # Get reference device endpoints
    reference_endpoints, _ = device_data[reference_device]
    reference_config_names = {ep.class_name for ep in reference_endpoints}

    # Build mapping: config_name -> normalized_tag_key
    # Separate objects: tagged (in groups), untagged from reference, and device-specific
    config_to_normalized_tag = {}
    reference_untagged = []
    device_specific = []

    # Create ordered list of normalized tags from reference device
    reference_normalized_tag_order = []
    normalized_tag_seen = set()

    # Process reference device configurations to establish tag order
    for endpoint in reference_endpoints:
        if endpoint.tags:
            for tag in endpoint.tags:
                normalized = _normalize_tag(tag)
                if normalized not in normalized_tag_seen:
                    reference_normalized_tag_order.append(normalized)
                    normalized_tag_seen.add(normalized)

    # Now map config objects to their normalized tags
    for endpoint in reference_endpoints:
        if endpoint.class_name in config_objects:
            if endpoint.tags:
                # Use first tag, normalized
                primary_tag = endpoint.tags[0]
                normalized_tag = _normalize_tag(primary_tag)
                config_to_normalized_tag[endpoint.class_name] = normalized_tag
            else:
                # Reference device object without tags - goes to separate group
                reference_untagged.append(endpoint.class_name)
                config_to_normalized_tag[endpoint.class_name] = "UNTAGGED"

    # Process configuration objects from other devices
    # Try to match them to existing normalized tags
    for config_name in config_objects:
        if config_name not in reference_config_names:
            # This config exists in other devices but not in reference
            # Try to find it in any device and get its normalized tag
            found = False
            for device_type, (endpoints, _) in device_data.items():
                endpoint = next((ep for ep in endpoints if ep.class_name == config_name), None)
                if endpoint and endpoint.tags:
                    normalized_tag = _normalize_tag(endpoint.tags[0])
                    # Check if this normalized tag already exists in reference
                    if normalized_tag in normalized_tag_seen:
                        config_to_normalized_tag[config_name] = normalized_tag
                        found = True
                        break
            if not found:
                # Device-specific object that doesn't match any known tag
                device_specific.append(config_name)
                config_to_normalized_tag[config_name] = "DEVICE-SPECIFIC"

    # Build tag order including special groups at end
    tag_order = list(reference_normalized_tag_order)

    if reference_untagged:
        tag_order.append("UNTAGGED")
    if device_specific:
        tag_order.append("DEVICE-SPECIFIC")

    # Build tag_groups dictionary with normalized tags as keys
    tag_groups = {tag: [] for tag in tag_order}
    for config_name in config_objects:
        normalized_tag = config_to_normalized_tag.get(config_name)
        if normalized_tag and normalized_tag in tag_groups:
            tag_groups[normalized_tag].append(config_name)

    # Report grouping statistics
    print(f"ℹ️  Grouped configuration objects into {len(tag_groups)} tag groups.")
    if reference_untagged:
        print(f"    - {len(reference_untagged)} object(s) from {reference_device} without tags")
    if device_specific:
        print(f"    - {len(device_specific)} device-specific object(s)")

    return reference_device, tag_groups


def _generate_header(f):
    """Generate the document header."""
    f.write("# Device Configuration Overview\n\n")
    f.write(
        "This table shows which configuration objects are supported by each device type. "
        "Further technical information can be found in the [README.md](../README.md) in section "
        "[sensor-configuration](../README.md#sensor-configuration). "
        "Examples of configuration programming can be found in [examples/shared/configuration.cpp](../examples/shared/configuration.cpp).\n\n"
    )


def _generate_table(f, device_data: Dict[str, Tuple[List[EndpointDescription], str]], config_objects: List[str], tag_groups: Dict[str, List[str]]):
    """
    Generate the markdown table with configuration objects and device support.
    Configuration objects are matched across devices using exact name matching.
    Objects are grouped by tags with rows showing the tag name in bold separating groups.

    Args:
        f: File handle to write to
        device_data: Dictionary mapping device_type -> (endpoint_descriptions, device_version)
        config_objects: List of all configuration object names to include
        tag_groups: Dictionary mapping normalized_tag_name -> list of config_object names in that group
    """
    device_types = sorted(device_data.keys())

    # Create a mapping of device_type -> config_name -> endpoint for quick lookup
    # This ensures exact name matching when checking device support
    device_configs = {}
    for device_type, (endpoints, _) in device_data.items():
        device_configs[device_type] = {ep.class_name: ep for ep in endpoints}

    # Prepare table headers
    headers = ["Configuration Object"] + device_types

    # Prepare table data
    table_data = []

    # First row: links to code
    link_row = [""]
    for device_type in device_types:
        # Use relative path from doc/ folder (where the markdown file is located)
        # Path needs ../ to go up from doc folder, then down to src
        link_path = f"../{API_INCLUDE_BASE_PATH}/{device_type}".replace("\\", "/")
        link_row.append(f"[link to code]({link_path})")
    table_data.append(link_row)

    # Generate rows grouped by tags
    for tag, config_names_in_group in tag_groups.items():
        # Add separator row with tag name in bold before each group
        if config_names_in_group:
            # Add row with tag name in bold as group header
            separator_row = [f"**{tag}**"] + [""] * len(device_types)
            table_data.append(separator_row)

        # Generate rows for each configuration object in this group
        for config_name in config_names_in_group:
            row_cells = [config_name]

            for device_type in device_types:
                endpoint = device_configs[device_type].get(config_name)

                # Apply filter: Check if this device supports this config object
                # Only show support (✅) if endpoint has GET or POST operations
                if endpoint and (endpoint.get is not None or endpoint.post is not None):
                    row_cells.append("✅")
                else:
                    row_cells.append("")

            table_data.append(row_cells)

    # Generate markdown table using tabulate
    # Use 'pipe' format which supports alignment markers (:---: for center)
    # Center-align device columns (all except the first "Configuration Object" column)
    colalign = ["left"] + ["center"] * len(device_types)
    markdown_table = tabulate(table_data, headers=headers, tablefmt="pipe", colalign=colalign)
    f.write(markdown_table)
    f.write("\n\n")
