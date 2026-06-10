import random


def ft_data_alchemist() -> None:
    print("=== Game Data Alchemist ===")
    print()
    players = [
        'Alice',
        'bob',
        'Charlie',
        'dylan',
        'Emma',
        'Gregory',
        'john',
        'kevin',
        'Liam'
    ]
    print(f"Initial list of players: {players}")
    capitalized = [player.capitalize() for player in players]
    print(f"New list with all names capitalized: {capitalized}")
    cap_filter = [player for player in players if
                  player == player.capitalize()]
    print(f"New list of capitalized names only: {cap_filter}")
    scores = {player: random.randint(0, 1000) for player in capitalized}
    print()
    print(f"Score dict: {scores}")
    avg_score = sum(scores.values()) / len(scores)
    print(f"Score average is {avg_score:.2f}")
    high_scores = {player: score for player, score in scores.items()
                   if score > avg_score}
    print(f"High scores: {high_scores}")


if __name__ == "__main__":
    ft_data_alchemist()
