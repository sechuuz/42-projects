from alchemy.potions import strength_potion
from ..elements import create_air
from elements import create_fire


def lead_to_gold() -> str:
    half = f"Recipe transmuting Lead to Gold: brew '{create_air()}' "
    return (half + f"and '{strength_potion()}' mixed with '{create_fire()}'")
