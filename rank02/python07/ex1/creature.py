from ex0.creature import Creature
from .capability import HealCapability, TransformCapability


class Sproutling(Creature, HealCapability):
    def __init__(self):
        super().__init__()
        self._name = "Sproutling"
        self._type = "Grass"

    def attack(self) -> str:
        return f"{self._name} uses Vine Whip!"

    def heal(self) -> str:
        return f"{self._name} heals itself for a small amount"


class Bloomelle(Creature, HealCapability):
    def __init__(self):
        super().__init__()
        self._name = "Bloomelle"
        self._type = "Grass/Fairy"

    def attack(self) -> str:
        return f"{self._name} uses Petal Dance!"

    def heal(self) -> str:
        return f"{self._name} heals itself and others for a large amount"


class Shiftling(Creature, TransformCapability):
    def __init__(self):
        super().__init__()
        self._name = "Shiftling"
        self._type = "Normal"

    def attack(self) -> str:
        if not self._is_transformed:
            return f"{self._name} attacks normally."
        return f"{self._name} performs a boosted strike!"

    def transform(self) -> str:
        if not self._is_transformed:
            self._is_transformed = True
            return f"{self._name} shifts into a sharper form!"
        return f"{self._name} is already transformed!"

    def revert(self) -> str:
        if self._is_transformed:
            self._is_transformed = False
            return f"{self._name} returns to normal."
        return f"{self._name} has not transformed yet!"


class Morphagon(Creature, TransformCapability):
    def __init__(self):
        super().__init__()
        self._name = "Morphagon"
        self._type = "Normal/Dragon"

    def attack(self) -> str:
        if not self._is_transformed:
            return f"{self._name} attacks normally."
        return f"{self._name} unleashes a devastating morph strike!"

    def transform(self) -> str:
        if not self._is_transformed:
            self._is_transformed = True
            return f"{self._name} morphs into a dragonic battle form!"
        return f"{self._name} is already transformed!"

    def revert(self) -> str:
        if self._is_transformed:
            self._is_transformed = False
            return f"{self._name} stabilizes its form."
        return f"{self._name} has not transformed yet!"
