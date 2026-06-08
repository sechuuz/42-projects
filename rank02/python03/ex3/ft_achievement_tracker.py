import random


def gen_player_achievements() -> set:
    achievement_list = [
        'Crafting Genius',
        'Strategist',
        'World Savior',
        'Speed Runner',
        'Survivor',
        'Master Explorer',
        'Treasure Hunter',
        'Unstoppable',
        'First Steps',
        'Collector Supreme',
        'Untouchable',
        'Sharp Mind',
        'Boss Slayer',
        'Hidden Path Finder'
        ]

    ach_num = random.randint(5, len(achievement_list))

    return set(random.sample(achievement_list, ach_num))


def ft_achievement_tracker() -> None:
    print("=== Achievement Tracker System ===")
    print()
    achievement_list = {
        'Crafting Genius',
        'Strategist',
        'World Savior',
        'Speed Runner',
        'Survivor',
        'Master Explorer',
        'Treasure Hunter',
        'Unstoppable',
        'First Steps',
        'Collector Supreme',
        'Untouchable',
        'Sharp Mind',
        'Boss Slayer',
        'Hidden Path Finder'
        }
    pdb = [
        gen_player_achievements(),
        gen_player_achievements(),
        gen_player_achievements(),
        gen_player_achievements()
    ]
    print(f"Player Alice: {pdb[0]}")
    print(f"Player Bob: {pdb[1]}")
    print(f"Player Charlie: {pdb[2]}")
    print(f"Player Dylan: {pdb[3]}")
    print()
    distinct = pdb[0].union(pdb[1], pdb[2], pdb[3])
    print(f"All distinct achievements: {distinct}")
    print()
    common = pdb[0].intersection(pdb[1], pdb[2], pdb[3])
    print(f"Common achievements: {common}")
    print()
    print(f"Only Alice has: {pdb[0].difference(pdb[1], pdb[2], pdb[3])}")
    print(f"Only Bob has: {pdb[1].difference(pdb[0], pdb[2], pdb[3])}")
    print(f"Only Charlie has: {pdb[2].difference(pdb[0], pdb[1], pdb[3])}")
    print(f"Only Dylan has: {pdb[3].difference(pdb[0], pdb[1], pdb[2])}")
    print()
    print(f"Alice is missing: {achievement_list.difference(pdb[0])}")
    print(f"Bob is missing: {achievement_list.difference(pdb[1])}")
    print(f"Charlie is missing: {achievement_list.difference(pdb[2])}")
    print(f"Dylan is missing: {achievement_list.difference(pdb[3])}")


if __name__ == "__main__":
    ft_achievement_tracker()
