from collections.abc import Callable
from typing import Any


def spell_combiner(spell1: Callable, spell2: Callable) -> Callable:
    def combined_spell(target: str, power: int) -> tuple[Any, Any]:
        return (spell1(target, power), spell2(target, power))
    return combined_spell


def power_amplifier(base_spell: Callable, multiplier: int) -> Callable:
    def amplified_spell(target: str, power: int) -> Any:
        return base_spell(target, power * multiplier)
    return amplified_spell


def conditional_caster(condition: Callable, spell: Callable) -> Callable:
    def conditional_spell(*args: Any, **kwargs: Any) -> Any:
        if condition(*args, **kwargs):
            return spell(*args, **kwargs)
        return "Spell fizzled"
    return conditional_spell


def spell_sequence(spells: list[Callable]) -> Callable:
    def sequence(target: str, power: int) -> list[Any]:
        return [spell(target, power) for spell in spells]
    return sequence


def higher_magic() -> None:
    def heal(target: str, power: int) -> str:
        return f"Heals {target}"

    def fireball(target: str, power: int) -> str:
        return f"Fireball hits {target}"

    def get_power(target: str, power: int) -> int:
        return power

    print("Testing spell combiner...")
    cmb = spell_combiner(fireball, heal)
    cmbatt = cmb("Dragon", 5)
    print(f"Combined spell result: {cmbatt[0]}, {cmbatt[1]}")
    print()
    print("Testing power amplifier...")
    amp = power_amplifier(get_power, 3)
    print(f"Original: {get_power('Test', 10)}, "
          f"Amplified: {amp('Test', 10)}")


if __name__ == "__main__":
    higher_magic()
