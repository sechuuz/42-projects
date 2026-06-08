from ex0 import FlameFactory, AquaFactory


def battle() -> None:
    print("Testing factory")
    flamefactory = FlameFactory()
    flameling = flamefactory.create_base()
    print(flameling.describe())
    print(flameling.attack())
    pyrodon = flamefactory.create_evolved()
    print(pyrodon.describe())
    print(pyrodon.attack())
    print()
    print("Testing factory")
    aquafactory = AquaFactory()
    aquabub = aquafactory.create_base()
    print(aquabub.describe())
    print(aquabub.attack())
    torragon = aquafactory.create_evolved()
    print(torragon.describe())
    print(torragon.attack())
    print()
    print("Testing battle")
    print(flameling.describe())
    print(" vs.")
    print(aquabub.describe())
    print(" fight!")
    print(flameling.attack())
    print(aquabub.attack())


if __name__ == "__main__":
    battle()
