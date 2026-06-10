from ex0 import FlameFactory, AquaFactory
from ex1 import HealingCreatureFactory, TransformCreatureFactory
from ex2 import NormalStrategy, AggressiveStrategy, \
                DefensiveStrategy, BattleError
from ex0.creature_factory import CreatureFactory
from ex2.battle_strategy import BattleStrategy


def battle(opponents: list[tuple[CreatureFactory, BattleStrategy]]) -> None:
    print("*** Tournament ***")
    print(f"{len(opponents)} opponents involved")
    creatures = [(factory.create_base(), strategy)
                 for factory, strategy in opponents]
    for i in range(len(creatures)):
        for j in range(i + 1, len(creatures)):
            creature1, strat1 = creatures[i]
            creature2, strat2 = creatures[j]
            print()
            print("* Battle *")
            print(creature1.describe())
            print(" vs.")
            print(creature2.describe())
            print(" now fight!")
            try:
                strat1.act(creature1)
                strat2.act(creature2)
            except BattleError as err:
                print(f"Battle error, aborting tournament: {err}")
                return


def tournament() -> None:
    flamefac = FlameFactory()
    aquafac = AquaFactory()
    healfac = HealingCreatureFactory()
    tranfac = TransformCreatureFactory()
    normstrat = NormalStrategy()
    aggstrat = AggressiveStrategy()
    defstrat = DefensiveStrategy()
    print("Tournament 0 (basic)")
    print("[ (Flameling+Normal), (Healing+Defensive) ]")
    battle(
        [
            (flamefac, normstrat),
            (healfac, defstrat)
        ]
    )
    print()
    print("Tournament 1 (error)")
    print("[ (Flameling+Aggressive), (Healing+Defensive) ]")
    battle(
        [
            (flamefac, aggstrat),
            (healfac, defstrat)
        ]
    )
    print()
    print("Tournament 2 (multiple)")
    print("[ (Aquabub+Normal), (Healing+Defensive), (Transform+Aggressive) ]")
    battle(
        [
            (aquafac, normstrat),
            (healfac, defstrat),
            (tranfac, aggstrat)
        ]
    )


if __name__ == "__main__":
    tournament()
