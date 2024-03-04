def recursive_search(data, target):
    for key, value in data.items():
        if key == target:
            return value
        elif isinstance(value, dict):
            return recursive_search(value, target)
        elif isinstance(value, list):
            for item in value:
                if isinstance(item, dict):
                    result = recursive_search(item, target)
                    if result:
                        return result
    return None

nested_dict = {
    "level1": {
        "level2": {
            "level3a": 7,
            "level3b": ["red", {"target_key": "hello, world"}]
        },
        "another_level2": {
            "level3": 8
        }
    },
    "another_level1": {
        "level2": 9
    }
}

print(recursive_search(nested_dict, "target_key"))
