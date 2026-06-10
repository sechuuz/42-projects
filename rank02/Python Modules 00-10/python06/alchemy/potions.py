from alchemy.elements import create_air, create_earth
from elements import create_fire, create_water


def healing_potion() -> str:
    brewed = "Healing potion brewed with "
    return (brewed + f"'{create_earth()}' and '{create_air()}'")


def strength_potion() -> str:
    brewed = "Strength potion brewed with "
    return (brewed + f"'{create_fire()}' and '{create_water()}'")
