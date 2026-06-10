from ex1 import HealingCreatureFactory, TransformCreatureFactory


def capacitor() -> None:
    print("Testing Creature with healing capability")
    healfactory = HealingCreatureFactory()
    print(" base:")
    sproutling = healfactory.create_base()
    print(sproutling.describe())
    print(sproutling.attack())
    print(sproutling.heal())
    print(" evolved:")
    bloomelle = healfactory.create_evolved()
    print(bloomelle.describe())
    print(bloomelle.attack())
    print(bloomelle.heal())
    print()
    print("Testing Creature with transform capability")
    transfactory = TransformCreatureFactory()
    print(" base:")
    shiftling = transfactory.create_base()
    print(shiftling.describe())
    print(shiftling.attack())
    print(shiftling.transform())
    print(shiftling.attack())
    print(shiftling.revert())
    print(" evolved:")
    morphagon = transfactory.create_evolved()
    print(morphagon.describe())
    print(morphagon.attack())
    print(morphagon.transform())
    print(morphagon.attack())
    print(morphagon.revert())


if __name__ == "__main__":
    capacitor()
