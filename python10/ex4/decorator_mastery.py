from collections.abc import Callable
from typing import Any
import functools
import time


def spell_timer(func: Callable) -> Callable:
    @functools.wraps(func)
    def wrapper(*args: Any, **kwargs: Any) -> Any:
        print(f"Casting {func.__name__}...")
        start = time.time()
        result = func(*args, **kwargs)
        end = time.time()
        print(f"Spell completed in {end - start:.3f} seconds")
        return result
    return wrapper


def power_validator(min_power: int) -> Callable:
    def decorator(func: Callable) -> Callable:
        @functools.wraps(func)
        def wrapper(*args: Any, **kwargs: Any) -> Any:
            if "power" in kwargs:
                power = kwargs["power"]
            else:
                power = args[-1]
            if int(power) >= min_power:
                return func(*args, **kwargs)
            return "Insufficient power for this spell"
        return wrapper
    return decorator


def retry_spell(max_attempts: int) -> Callable:
    def decorator(func: Callable) -> Callable:
        @functools.wraps(func)
        def wrapper(*args: Any, **kwargs: Any) -> Any:
            for i in range(1, max_attempts + 1):
                try:
                    return func(*args, **kwargs)
                except Exception:
                    print("Spell failed, retrying... "
                          f"({i}/{max_attempts})")
            return f"Spell casting failed after {max_attempts} attempts"
        return wrapper
    return decorator


class MageGuild:
    @staticmethod
    def validate_mage_name(name: str) -> bool:
        if len(name) < 3:
            return False
        return all(char.isalpha() or char.isspace() for char in name)

    @power_validator(10)
    def cast_spell(self, spell_name: str, power: int) -> str:
        return f"Successfully cast {spell_name} with {power} power"


def decorator_mastery() -> None:
    print("Testing spell timer...")

    @spell_timer
    def fireball() -> str:
        return "Fireball cast!"

    timed = fireball()
    print(f"Result: {timed}")
    print()
    print("Testing retrying spell...")

    @retry_spell(3)
    def invalidspell() -> None:
        raise Exception("this is supposed to happen!!!")

    @retry_spell(3)
    def validspell() -> str:
        return "Waaaaaaagh spelled !"

    print(invalidspell())
    print(validspell())
    print()
    print("Testing MageGuild...")
    guild = MageGuild()
    print(guild.validate_mage_name("Magus Guilder"))
    print(guild.validate_mage_name("42 1337"))
    print(guild.cast_spell("Lightning", 15))
    print(guild.cast_spell("Spark", 5))


if __name__ == "__main__":
    decorator_mastery()
