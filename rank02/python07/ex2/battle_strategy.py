from abc import ABC, abstractmethod
from ex0.creature import Creature
from ex1.capability import HealCapability, TransformCapability
from typing import Any


class BattleError(Exception):
    def __init__(self, message="Battle error occured"):
        super().__init__(message)


class BattleStrategy(ABC):
    def __init__(self):
        super().__init__()

    @abstractmethod
    def act(self, creature: Any) -> None:
        pass

    @abstractmethod
    def is_valid(self, creature: Any) -> bool:
        pass


class NormalStrategy(BattleStrategy):
    def __init__(self):
        super().__init__()

    def act(self, creature: Any) -> None:
        if self.is_valid(creature):
            print(creature.attack())
            return
        raise BattleError(f"Invalid Creature '{creature._name}' "
                          "for this normal strategy")

    def is_valid(self, creature: Any) -> bool:
        if isinstance(creature, Creature):
            return True
        return False


class AggressiveStrategy(BattleStrategy):
    def __init__(self):
        super().__init__()

    def act(self, creature: Any) -> None:
        if self.is_valid(creature):
            print(creature.transform())
            print(creature.attack())
            print(creature.revert())
            return
        raise BattleError(f"Invalid Creature '{creature._name}' "
                          "for this aggressive strategy")

    def is_valid(self, creature: Any) -> bool:
        if isinstance(creature, TransformCapability):
            return True
        return False


class DefensiveStrategy(BattleStrategy):
    def __init__(self):
        super().__init__()

    def act(self, creature: Any) -> None:
        if self.is_valid(creature):
            print(creature.attack())
            print(creature.heal())
            return
        raise BattleError(f"Invalid Creature '{creature._name}' "
                          "for this defensive strategy")

    def is_valid(self, creature: Any) -> bool:
        if isinstance(creature, HealCapability):
            return True
        return False
