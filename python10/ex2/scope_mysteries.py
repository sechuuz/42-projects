from collections.abc import Callable
from typing import Any


def mage_counter() -> Callable:
    count = 0

    def in_counter() -> int:
        nonlocal count
        count += 1
        return count

    return in_counter


def spell_accumulator(initial_power: int) -> Callable:
    accumulated = initial_power

    def in_accumulator(power: int) -> int:
        nonlocal accumulated
        accumulated += power
        return accumulated

    return in_accumulator


def enchantment_factory(enchantment_type: str) -> Callable:
    def in_enchanter(item: str) -> str:
        return f"{enchantment_type} {item}"
    return in_enchanter


def memory_vault() -> dict[str, Callable]:
    vault = {}

    def store(key: str, value: Any) -> None:
        vault[key] = value

    def recall(key: str) -> Any:
        return vault.get(key, "Memory not found")

    return {"store": store, "recall": recall}


def scope_mysteries() -> None:
    print("Testing mage counter...")
    counter_a = mage_counter()
    counter_b = mage_counter()
    print(f"counter_a call 1: {counter_a()}")
    print(f"counter_a call 2: {counter_a()}")
    print(f"counter_a call 1: {counter_b()}")
    print()
    print("Testing spell accumulator...")
    accumulator = spell_accumulator(100)
    print(f"Base 100, add 20: {accumulator(20)}")
    print(f"Base 100, add 30: {accumulator(30)}")
    print()
    print("Testing enchantment factory...")
    flaming = enchantment_factory("Flaming")
    print(f"{flaming('Sword')}")
    frozen = enchantment_factory("Frozen")
    print(f"{frozen('Shield')}")
    print()
    print("Testing memory vault...")
    vault = memory_vault()
    print("Store 'secret' = 42")
    vault["store"]("secret", 42)
    print(f"Recall 'secret': {vault['recall']('secret')}")
    print(f"Recall 'unknown': {vault['recall']('unknown')}")


if __name__ == "__main__":
    scope_mysteries()
