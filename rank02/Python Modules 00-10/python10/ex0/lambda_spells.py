def artifact_sorter(artifacts: list[dict]) -> list[dict]:
    return sorted(artifacts, key=lambda a: a.get("power", 0), reverse=True)


def power_filter(mages: list[dict], min_power: int) -> list[dict]:
    return list(filter(lambda a: a.get("power", 0) >= min_power, mages))


def spell_transformer(spells: list[str]) -> list[str]:
    return list(map(lambda a: f"* {a} *", spells))


def mage_stats(mages: list[dict]) -> dict:
    if not mages:
        return {
            'max_power': 0,
            'min_power': 0,
            'avg_power': 0
        }
    maxpow = max(mages, key=lambda a: a.get("power", 0)).get("power", 0)
    minpow = min(mages, key=lambda a: a.get("power", 0)).get("power", 0)
    allpow = sum(map(lambda a: a.get("power", 0), mages))
    try:
        avg = round(allpow / len(mages), 2)
    except ZeroDivisionError:
        return {
            'max_power': 0,
            'min_power': 0,
            'avg_power': 0
        }
    return {
        'max_power': maxpow,
        'min_power': minpow,
        'avg_power': avg
    }


def lambda_spells() -> None:
    artifacts = [
        {'name': 'Crystal Orb', 'power': 85, 'type': 'weapon'},
        {'name': 'Fire Staff', 'power': 92, 'type': 'weapon'}
    ]
    print()
    print("Testing artifact sorter...")
    sorted_artifacts = artifact_sorter(artifacts)
    print(f"{sorted_artifacts[0]['name']} "
          f"({sorted_artifacts[0]['power']} power) "
          "comes before "
          f"{sorted_artifacts[1]['name']} "
          f"({sorted_artifacts[1]['power']} power)")
    print()
    print("Testing spell transformer...")
    spells = [
        "fireball",
        "heal",
        "shield"
    ]
    transformed_spells = spell_transformer(spells)
    print(transformed_spells[0], end=" ")
    print(transformed_spells[1], end=" ")
    print(transformed_spells[2])


if __name__ == "__main__":
    lambda_spells()
