from io import TextIOWrapper
import os
from typing import List, Optional, Set
from datetime import datetime

from objects import *


DATA_OBJECT_OUT_DIR = os.path.join("src/sensor_configuration/include/sick_perception_sdk/sensor_configuration/api")
MEMBER_PREFIX = "_"


def generate_code(endpoints: List[EndpointDescription], device_type: str, device_version: str):
    out_dir = os.path.abspath(os.path.join(DATA_OBJECT_OUT_DIR, device_type))
    print(f"ℹ️  Generating output in '{out_dir}'...")

    if not os.path.exists(out_dir):
        os.makedirs(out_dir)

    for endpoint in endpoints:
        file_name = f"{endpoint.class_name}.g.hpp"
        full_file_name = os.path.join(out_dir, file_name)

        f = open(full_file_name, "w")
        _generate_file_header(f, file_name, device_type, device_version, endpoint)

        includes = set()
        includes.add("#include <sick_perception_sdk/common/export.hpp>")
        for method in endpoint.get, endpoint.post:
            if method is not None:
                if method.request_payload is not None:
                    _collect_includes(method.request_payload, includes)
                if method.response_payload is not None:
                    _collect_includes(method.response_payload, includes)
        includes = sorted(includes)
        _generate_includes(f, includes)

        _generate_namespaces_start(f, device_type)

        name_of_name_member = "variableName" if not endpoint.is_sopas_method else "methodName"

        f.write(f"/**\n")
        f.write(f" * @brief Payloads for endpoint {endpoint.path}.\n")
        f.write(f"*/\n")
        f.write(f"struct SDK_EXPORT {endpoint.class_name}\n{{\n\n")
        f.write(f'  constexpr static const char* {name_of_name_member} = "{endpoint.class_name}";\n')
        f.write(f"  constexpr static const bool isSopasMethod = {str(endpoint.is_sopas_method).lower()};\n\n")
        _generate_objects_for_endpoint_method(f, endpoint.get)
        _generate_objects_for_endpoint_method(f, endpoint.post)
        f.write(f"}}; // struct {endpoint.class_name}\n\n")
        _generate_namespaces_end(f, device_type)

        f.close()

    _generate_json(endpoints, device_type, device_version)

    _generate_device_include(endpoints, device_type, device_version)


def _generate_objects_for_endpoint_method(f: TextIOWrapper, method: Optional[EndpointMethodDescription]):
    if method is None:
        return

    if method.description is not None:
        f.write(f"/**\n")
        f.write(f" * @brief {method.description}\n")
        f.write(f"*/\n")

    f.write(f"struct SDK_EXPORT {method.method}\n{{\n")

    _generate_object_for_payload(f, method.request_payload)
    _generate_object_for_payload(f, method.response_payload)

    f.write(f"}}; // struct {method.method}\n\n")


def _generate_object_for_payload(f: TextIOWrapper, payload: Optional[ObjectDescription]):
    if payload is None:
        return

    _generate_object(f, payload, 0)
    f.write("\n")


def _generate_json(endpoints: List[EndpointDescription], device_type: str, device_version: str):
    out_dir = os.path.abspath(os.path.join(DATA_OBJECT_OUT_DIR, "json"))
    if not os.path.exists(out_dir):
        os.makedirs(out_dir)

    file_name = f"{device_type}.g.hpp"
    full_file_name = os.path.join(out_dir, file_name)
    print(f"ℹ️  Generating JSON output in '{file_name}'...")
    f = open(full_file_name, "w")
    _generate_file_header(f, file_name, device_type, device_version, None)

    f.write(f"#include <sick_perception_sdk/sensor_configuration/api/{device_type}.g.hpp>\n")
    f.write(f"#include <nlohmann/json.hpp>\n")
    f.write(f"\n")

    _generate_namespaces_start(f, device_type)

    for endpoint in endpoints:
        class_name = endpoint.path.replace("/", "")
        _generate_json_for_endpoint_method(f, endpoint, endpoint.get, class_name)
        _generate_json_for_endpoint_method(f, endpoint, endpoint.post, class_name)

    _generate_namespaces_end(f, device_type)

    f.close()


def _generate_json_for_endpoint_method(f, endpoint: EndpointDescription, method: Optional[EndpointMethodDescription], class_name):
    if method is None:
        return

    class_name = class_name + "::" + method.method
    _generate_json_for_payload(f, endpoint, method.request_payload, class_name)
    _generate_json_for_payload(f, endpoint, method.response_payload, class_name)


def _generate_json_for_payload(f, endpoint: EndpointDescription, payload: Optional[ObjectDescription], class_name):
    if payload is None:
        return
    _generate_json_for_object(f, endpoint, payload, class_name)
    f.write("\n")


def _generate_device_include(endpoints: List[EndpointDescription], device_type: str, device_version: str):
    out_dir = os.path.abspath(os.path.join(DATA_OBJECT_OUT_DIR))
    if not os.path.exists(out_dir):
        os.makedirs(out_dir)

    file_name = f"{device_type}.g.hpp"
    full_file_name = os.path.join(out_dir, file_name)
    print(f"ℹ️  Generating device include header in '{file_name}'...")
    f = open(full_file_name, "w")
    _generate_file_header(f, file_name, device_type, device_version, None)

    for endpoint in endpoints:
        class_name = endpoint.path.replace("/", "")
        f.write(f"#include <sick_perception_sdk/sensor_configuration/api/{device_type}/{class_name}.g.hpp>\n")
    f.write(f"\n")

    f.close()


def _generate_file_header(f: TextIOWrapper, file_name: str, device_type: str, device_version: str, endpoint: Optional[EndpointDescription]):
    f.write(f"/*\n")
    f.write(f"Copyright (c) {datetime.now().strftime('%Y')} SICK AG\n")
    f.write(f"SPDX-License-Identifier: MIT\n")
    f.write(f"*/\n")
    f.write(f"\n")

    f.write(f"/**\n")
    f.write(f" * @file {file_name} Sensor REST API payload definitions.\n")
    f.write(f" * @warning This file was generated for device '{device_type}' version '{device_version}'.\n")
    f.write(f" * Do not edit manually!\n")

    if endpoint and endpoint.is_sopas_method:
        f.write(f" *\n")
        f.write(f" * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!\n")

    f.write(f" */\n")

    f.write(f"#pragma once\n")
    f.write(f"\n")


def _generate_includes(f: TextIOWrapper, includes: List[str]):
    for include in includes:
        f.write(f"{include}\n")
    f.write(f"\n")


def _generate_namespaces_start(f: TextIOWrapper, device_type: str):
    f.write(f"namespace sick::srt::{device_type} {{\n\n")


def _generate_namespaces_end(f: TextIOWrapper, device_type: str):
    f.write(f"}} // namespace sick::srt::{device_type}\n")


def _generate_ctors(f: TextIOWrapper, name, obj: ObjectDescription, indent: int):
    indent_str = " " * indent
    # Generate default constructor (required for from_json)
    f.write(f"{indent_str}  {name}() = default;\n")
    f.write("\n")

    # Generate constructor with all fields as parameters
    f.write(f"{indent_str}  explicit {name}(")
    params = []
    for field in obj.fields:
        params.append(f"{field.type} {field.name}")
    f.write(", ".join(params))
    f.write(")\n")
    if obj.fields:
        f.write(f"{indent_str}    : ")
        inits = []
        for field in obj.fields:
            if field.type == "std::string" or field.type.startswith("NumericRange"):
                inits.append(f"{MEMBER_PREFIX}{field.name}(std::move({field.name}))")
            else:
                inits.append(f"{MEMBER_PREFIX}{field.name}({field.name})")
        f.write(", ".join(inits))
        f.write("\n")
    f.write(f"{indent_str}  {{}}\n")


def _generate_json_for_object(f: TextIOWrapper, endpoint: Optional[EndpointDescription], object: ObjectDescription, class_name: str):
    # Here the full class name with all namespaces is required because the to_json and from_json functions
    # are defined outside of the classes.
    class_name = class_name + "::" + object.class_name

    # First generate the to_json and from_json functions for all sub-objects.
    for sub_object in object.objects:
        _generate_json_for_object(f, None, sub_object, class_name)

    # Generate the to_json function to serialize the object to JSON.
    f.write(f"inline void to_json(nlohmann::ordered_json& j, {class_name} const& obj)\n")
    f.write(f"{{\n")

    # Special handling for objects at top level. If the object has only one field its value
    # must not be accessed by name because the name access is already done by the caller
    # (for accessing the first level inside the `data` field).
    is_sopas_method = endpoint.is_sopas_method if endpoint else False
    if len(object.fields) == 1 and object.parent is None and not is_sopas_method:
        field = object.fields[0]
        if field.type.startswith("NumericRange"):
            f.write(f"  j = obj.{MEMBER_PREFIX}{field.name}.value();\n")
        else:
            f.write(f"  j = obj.{MEMBER_PREFIX}{field.name};\n")
    else:
        f.write(f"  j = nlohmann::ordered_json{{\n")
        for field in object.fields:
            if field.type.startswith("NumericRange"):
                f.write(f'      {{"{field.name}", obj.{MEMBER_PREFIX}{field.name}.value()}},\n')
            else:
                f.write(f'      {{"{field.name}", obj.{MEMBER_PREFIX}{field.name}}},\n')
        f.write(f"  }};\n")
    f.write(f"}}\n")
    f.write(f"\n")

    # Generate the from_json function to deserialize the object from JSON.
    f.write(f"inline void from_json(const nlohmann::json& j, {class_name}& obj)\n")
    f.write(f"{{\n")
    # Special handling for objects at top level. If the object has only one field its value
    # must not be accessed by name because the name access is already done by the caller
    # (for accessing the first level inside the `data` field).
    if len(object.fields) == 1 and object.parent is None and not is_sopas_method:
        field = object.fields[0]
        f.write(f"  j.get_to(obj.{MEMBER_PREFIX}{field.name});\n")
    else:
        for field in object.fields:
            f.write(f'  j.at("{field.name}").get_to(obj.{MEMBER_PREFIX}{field.name});\n')
    f.write(f"}}\n")
    f.write(f"\n")


def _generate_object(f: TextIOWrapper, obj: ObjectDescription, indent: int):
    indent_str = " " * indent

    if obj.description:
        f.write(f"{indent_str}/**\n")
        prefix = "@brief"
        for line in obj.description.split("\n"):
            f.write(f"{indent_str} * {prefix} {line}\n")
            prefix = ""
        f.write(f"{indent_str} */\n")

    f.write(f"{indent_str}struct SDK_EXPORT {obj.class_name}\n")
    f.write(f"{indent_str}{{\n")

    for enum in obj.enums:
        f.write(f"{indent_str}  enum class {enum.class_name}\n")
        f.write(f"{indent_str}  {{\n")
        for field in enum.fields:
            f.write(f"{indent_str}    {field.name} = {field.type},\n")
        f.write(f"{indent_str}  }};\n")
        f.write("\n")

    for sub_obj in obj.objects:
        _generate_object(f, sub_obj, indent + 2)
        f.write("\n")

    _generate_ctors(f, obj.class_name, obj, indent)
    f.write("\n")

    for field in obj.fields:
        f.write(f"{indent_str}  {field.type} {MEMBER_PREFIX}{field.name};\n")
    f.write(f"{indent_str}}};\n")


def _collect_includes(obj: ObjectDescription, includes: Set[str]) -> None:
    """
    Flatten all includes of our object tree: recursively collect all includes from the object
    and its sub-objects.
    """
    includes.update(obj.includes)
    for sub_obj in obj.objects:
        _collect_includes(sub_obj, includes)
