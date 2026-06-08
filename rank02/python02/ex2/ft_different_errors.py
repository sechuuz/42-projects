def garden_operations(operation_number: float) -> None:
    if (operation_number == 0):
        int("abc")
    elif (operation_number == 1):
        operation_number = 42 / 0
    elif (operation_number == 2):
        open("thisFileDoesNotExist", "r")
    elif (operation_number == 3):
        operation_number()
    else:
        return


def test_error_types():
    print("=== Garden Error Types Demo ===")
    cases = [0, 1, 2, 3, 4]
    for case in cases:
        print(f"Testing operation {case}...")
        try:
            garden_operations(case)
            print("Operation completed successfully")
        except ValueError as err:
            print(f"Caught ValueError: {err}")
        except ZeroDivisionError as err:
            print(f"Caught ZeroDivisionError: {err}")
        except FileNotFoundError as err:
            print(f"Caught FileNotFoundError: {err}")
        except TypeError as err:
            print(f"Caught TypeError: {err}")
    print("\nAll error types tested successfully!")


if __name__ == "__main__":
    test_error_types()
