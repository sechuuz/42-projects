from alchemy.grimoire.dark_spellbook import dark_spell_record


def ft_kaboom_1() -> None:
    print("=== Kaboom 1 ===")
    print("Access to alchemy/grimoire/dark_spellbook.py directly")
    print('Test import now - : THIS WILL RAISE AN UNCAUGHT EXCEPTION'
          f'{dark_spell_record("Fantasy", "Earth, wind and fire")}')


if __name__ == "__main__":
    ft_kaboom_1()
