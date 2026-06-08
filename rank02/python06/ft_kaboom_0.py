from alchemy.grimoire import light_spell_record


def ft_kaboom_0() -> None:
    print("=== Kaboom 0 ===")
    print("Using grimoire module directly")
    print('Testing record light spell: '
          f'{light_spell_record("Fantasy", "Earth, wind and fire")}')


if __name__ == "__main__":
    ft_kaboom_0()
