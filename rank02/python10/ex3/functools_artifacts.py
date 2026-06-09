from collections.abc import Callable
from typing import Any
import functools
import operator


def spell_reducer(spells: list[int], operation: str) -> int:
    if not spells:
        return 0
    operations: dict[str, Callable] = {
        "add": operator.add,
        "multiply": operator.mul,
        "max": max,
        "min": min
    }
    if operation not in operations:
        print("Unknown operation!")
        return 0
    return functools.reduce(operations[operation], spells)


def partial_enchanter(base_enchantment: Callable) -> dict[str, Callable]:
    return {
        "fire": functools.partial(base_enchantment, 50, "fire"),
        "water": functools.partial(base_enchantment, 50, "water"),
        "earth": functools.partial(base_enchantment, 50, "earth")
    }


@functools.lru_cache(maxsize=None)
def memoized_fibonacci(n: int) -> int:
    if n < 2:
        return n
    return memoized_fibonacci(n - 1) + memoized_fibonacci(n - 2)


def spell_dispatcher() -> Callable[[Any], str]:
    @functools.singledispatch
    def in_dispatcher(arg: Any) -> str:
        return "Unknown spell type"

    @in_dispatcher.register(int)
    def damage(dmg: int) -> str:
        return f"Damage spell: {dmg} damage"

    @in_dispatcher.register(str)
    def enchant(ench: str) -> str:
        return f"Enchantment: {ench}"

    @in_dispatcher.register(list)
    def multicast(spells: list) -> str:
        return f"Multi-cast: {len(spells)} spells"

    return in_dispatcher


def functools_artifacts() -> None:
    print()
    print("Testing spell reducer...")
    spells = [10, 20, 30, 40]
    print(f"Sum: {spell_reducer(spells, 'add')}")
    print(f"Product: {spell_reducer(spells, 'multiply')}")
    print(f"Max: {spell_reducer(spells, 'max')}")
    print()
    print("Testing memoized fibonacci...")
    print(f"Fib(0): {memoized_fibonacci(0)}")
    print(f"Fib(1): {memoized_fibonacci(1)}")
    print(f"Fib(10): {memoized_fibonacci(10)}")
    print(f"Fib(15): {memoized_fibonacci(15)}")
    print()
    print("Testing spell dispatcher...")
    spell_dispatch = spell_dispatcher()
    print(spell_dispatch(42))
    print(spell_dispatch("fireball"))
    print(spell_dispatch([
        "spell1",
        "spell2",
        "spell3"
    ]))
    print(spell_dispatch(set("test")))


if __name__ == "__main__":
    functools_artifacts()
