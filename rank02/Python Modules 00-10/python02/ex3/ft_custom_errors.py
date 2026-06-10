class GardenError(Exception):
    def __init__(self, message="Unknown garden error"):
        super().__init__(message)


class PlantError(GardenError):
    def __init__(self, message="Unknown plant error"):
        super().__init__(message)


class WaterError(GardenError):
    def __init__(self, message="Unknown water error"):
        super().__init__(message)


def plant_test(name: str, is_wilting: bool) -> None:
    if is_wilting:
        raise PlantError(f"The {name} plant is wilting!")
    else:
        print(f"{name} isn't wilting!")


def water_test(water_amt: int) -> None:
    if water_amt < 5:
        raise WaterError("Not enough water in the tank!")
    else:
        print("There is enough water in the tank")


if __name__ == "__main__":
    print("=== Custom Garden Errors Demo ===")
    print()
    print("Testing PlantError...")
    try:
        plant_test("tomato", True)
    except PlantError as err:
        print(f"Caught PlantError: {err}")
    print()
    print("Testing WaterError...")
    try:
        water_test(1)
    except WaterError as err:
        print(f"Caught WaterError: {err}")
    print()
    print("Testing catching all garden errors...")
    try:
        plant_test("tomato", True)
    except GardenError as err:
        print(f"Caught GardenError: {err}")
    try:
        water_test(1)
    except GardenError as err:
        print(f"Caught GardenError: {err}")
    print()
    print("All custom error types work correctly!")
