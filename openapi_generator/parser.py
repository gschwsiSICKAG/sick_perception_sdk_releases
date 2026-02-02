from objects import *


def parse_path(path_name: str, path, endpoints: List[EndpointDescription]) -> None:
    """
    Parse an OpenAPI path and add its payload description to the list of payload objects.
    """

    endpoint_description = EndpointDescription(path_name)
    for method, operation in path.items():
        if method not in ["get", "post"]:
            print(f"⚠️  Method '{method}' of path '{path_name}' not supported. Skipping it.")
            continue

        method_class_name = "Get" if method == "get" else "Post"
        description = operation["description"].strip(" \n") if "description" in operation else None
        request = _parse_request_body(operation, path_name)
        response = _parse_response(operation, path_name, method)
        endpoint_method_description = EndpointMethodDescription(method_class_name, description, request, response)

        if method == "get":
            endpoint_description.get = endpoint_method_description
        else:
            endpoint_description.post = endpoint_method_description

    endpoint_description.is_sopas_method = _is_sopas_method(endpoint_description)
    endpoints.append(endpoint_description)


def _is_sopas_method(endpoint: EndpointDescription) -> bool:
    # An endpoint with a GET method can never be a SOPAS method.
    if endpoint.get is not None:
        return False

    # And endpoint without a POST method cannot be a SOPAS method.
    if endpoint.post is None:
        return False

    # If the POST method has no request payload it is likely to be a SOPAS method.
    if endpoint.post.request_payload is None:
        return True

    # Finally, if the class name of the endpoint differs from the class name of the POST request payload, it is a SOPAS method.
    if endpoint.class_name != endpoint.post.request_payload.class_name:
        return True

    return False


def _parse_request_body(operation, path_name: str) -> Optional[ObjectDescription]:
    if not "requestBody" in operation:
        return None

    schema = operation["requestBody"]["content"]["application/json"]["schema"]

    if not "properties" in schema:
        return None

    schema = schema["properties"]
    if not "data" in schema:
        return None

    schema = schema["data"]
    if not "properties" in schema:
        return None

    schema = schema["properties"]

    class_name = path_name.replace("/", "")
    if class_name in schema and schema[class_name]["type"] == "object":
        schema = schema[class_name]
    if "properties" in schema:
        schema = schema["properties"]

    return _parse_schema("Request", schema)


def _parse_response(operation, path_name: str, method: str) -> Optional[ObjectDescription]:
    # All SRT REST methods report 200, even if they fail. Therefore, an operation that does not have a 200 response is highly suspicious
    # and will be ignored.
    if "200" not in operation["responses"]:
        print(f"⚠️  Response 200 not found method '{method}' in path '{path_name}'. Skipping it.")
        return None

    # Parse the response schema
    # Here is a bold assumption that this sequence of objects leads us to our desired payload description.
    # The assumption seems to hold quite well because there are only very few objects where this is not the case.
    # We'll ignore these objects for now and let python throw an exception that one of the fields of the dictionary cannot be found.
    schema = operation["responses"]["200"]["content"]["application/json"]["schema"]["properties"]

    if not "data" in schema:
        return

    schema = schema["data"]
    if not "properties" in schema:
        return None

    schema = schema["properties"]
    return _parse_schema("Response", schema)


def _parse_schema(payload_name: str, schema) -> Optional[ObjectDescription]:
    payload = ObjectDescription(payload_name, parent=None)  # Each operation's payload is a top-level object.

    for sub_name, sub_prop in schema.items():
        parsed_prop_type = _parse_prop_type(sub_name, sub_prop, payload)
        payload.fields.append(FieldDescription(sub_name, parsed_prop_type))

    if not payload.fields:
        return None  # Skip empty payloads

    return payload


def _parse_array(prop_name, prop, parent: ObjectDescription) -> str:
    item_type = prop["items"]["type"]
    if item_type == "boolean":
        item_type_cpp = "bool"
    elif item_type == "integer":
        item_type_cpp = "int"
    elif item_type == "number":
        item_type_cpp = "float"
    elif item_type == "object":
        item_type_cpp = prop_name + "Item"
        _parse_object(item_type_cpp, prop["items"], parent)
    else:
        raise Exception(f"Array type mapping for '{item_type}' not implemented")

    min_number_of_items = prop["minItems"]
    max_number_of_items = prop["maxItems"]
    if min_number_of_items == max_number_of_items:
        return f"std::array<{item_type_cpp}, {min_number_of_items}>"
    else:
        return f"std::vector<{item_type_cpp}>"


def _parse_enum(prop_name: str, prop, parent: ObjectDescription) -> None:
    enum = EnumDescription(prop_name)

    # The description tells us the mapping of the enum values. Example:
    # ```
    #   Mapping:
    #    * 0 - SOPAS_ERR_NO_ERR
    #    * 1 - SOPAS_ERR_STATE_CHANGE_NOT_PERMITTED
    # ```
    description = prop["description"]

    lines = description.split("\n")
    lines.pop(0)  # The first line contains "Mapping:" and can be ignored

    for line in lines:
        line = line.strip()
        if not line or not line.startswith("*"):
            continue
        try:
            _, rest = line.split("*", 1)
            rest = rest.strip()
            value_str, name_str = rest.split("-", 1)
            field_value = value_str.strip()
            # Convert enum label to PascalCase for the C++ identifier
            field_name = _to_pascal_case(name_str.strip())
            enum.fields.append(EnumFieldDescription(field_name, field_value))
        except Exception as e:
            raise Exception(f"Failed to parse enum line: '{line}' ({e})")
    parent.enums.append(enum)


# New helper: convert arbitrary enum label to PascalCase and ensure valid identifier
def _to_pascal_case(s: str) -> str:
    """
    Convert a string like "SOPAS_ERR_NO_ERR" or "some-value/name" to "SopasErrNoErr".
    Non-alphanumeric separators are treated as word boundaries. If the result starts
    with a digit, prefix with an underscore to make a valid identifier.
    """
    import re

    # Replace non-alphanumeric characters with spaces, split into parts
    parts = re.split(r"[^0-9A-Za-z]+", s)
    # Filter out empty parts
    parts = [p for p in parts if p]
    if not parts:
        return "Unknown"

    # Capitalize each part (lowercase first to normalize acronyms)
    pascal_parts = [p.lower().capitalize() for p in parts]
    identifier = "".join(pascal_parts)

    # Ensure identifier doesn't start with a digit
    if identifier and identifier[0].isdigit():
        identifier = "_" + identifier

    # Remove any remaining invalid characters (keep alnum and underscore)
    identifier = re.sub(r"[^0-9A-Za-z_]", "", identifier)

    return identifier


def _parse_object(prop_name: str, prop, parent: ObjectDescription) -> None:
    """
    Resolve nested objects until only primitive types are left.
    This will call `parse_prop_type` recursively.
    """
    new_obj = ObjectDescription(prop_name, parent)

    for field_name, field_prop in prop["properties"].items():
        new_obj.fields.append(FieldDescription(field_name, _parse_prop_type(field_name, field_prop, new_obj)))

    parent.objects.append(new_obj)


def _parse_prop_type(prop_name, prop, obj: ObjectDescription) -> str:
    """
    Convert a SRT REST property type to a C++ type.
    """
    prop_type = prop["type"]
    if prop_type == "array":
        return _parse_array(prop_name, prop, obj)
    if prop_type == "boolean":
        return "bool"
    if prop_type == "integer":
        # Enums are a bit funny in that they contain an additional "enum" property.
        # In that case we know we have to apply special handling.
        if "enum" in prop:
            _parse_enum(prop_name, prop, obj)
            return prop_name

        # Properties that don't specify valid limits are handled like regular integers.
        if "minimum" not in prop or "maximum" not in prop:
            return "int"

        # We possibly add the includes multiple times. That's ok, we'll remove duplicates later.
        obj.includes.append("#include <sick_perception_sdk/sensor_configuration/api/NumericRange.hpp>")
        # Properties with a full specification will be converted to a `NumericRange` to make the C++ API self-documenting.
        min = prop["minimum"]
        max = prop["maximum"]

        if "default" in prop:
            default = prop["default"]
            return "NumericRange<" + str(min) + ", " + str(max) + ", " + str(default) + ">"
        else:
            return "NumericRange<" + str(min) + ", " + str(max) + ", 0>"
    if prop_type == "number":
        return "float"
    if prop_type == "object":
        _parse_object(prop_name, prop, obj)
        return prop_name
    if prop_type == "string":
        # We possibly add the includes multiple times. That's ok, we'll remove duplicates later.
        obj.includes.append("#include <string>")
        return "std::string"
    raise Exception(f"Type mapping for '{prop_type}' not implemented")
