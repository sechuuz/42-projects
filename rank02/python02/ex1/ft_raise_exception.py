def input_temperature(temp_str: str) -> int:
    print(f"Input data is '{temp_str}'")
    str_int = int(temp_str)
    if str_int > 40:
        raise ValueError(f"{str_int}°C is too hot for plants (max 40°C)")
    elif str_int < 0:
        raise ValueError(f"{str_int}°C is too cold for plants (min 0°C)")
    return str_int


def test_temperature():
    print("=== Garden Temperature Checker ===\n")
    try:
        print(f"Temperature is now {input_temperature('25')}°C")
        print("")
        input_temperature('abc')
    except ValueError as err:
        print(f"Caught input_temperature error: {err}")
    try:
        print()
        input_temperature('100')
    except ValueError as err:
        print(f"Caught input_temperature error: {err}")
    try:
        print()
        input_temperature('-50')
    except ValueError as err:
        print(f"Caught input_temperature error: {err}")
    print("\nAll tests completed - program didn't crash!")


if __name__ == "__main__":
    test_temperature()
