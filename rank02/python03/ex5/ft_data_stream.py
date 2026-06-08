import random
from typing import Generator


def gen_event() -> Generator[tuple[str, str], None, None]:
    players = ["dylan", "ben", "mark", "desmond", "saif", "brian"]
    actions = ["run", "walk", "swim", "sleep", "climb", "run", "bike"]
    while True:
        chosen = (random.choice(players), random.choice(actions))
        yield chosen


def consume_event(events: list[tuple[str, str]]) -> \
                  Generator[tuple[str, str], None, None]:
    while events:
        chosen = random.choice(events)
        events.remove(chosen)
        yield chosen


def ft_data_stream() -> None:
    print("=== Game Data Stream Processor ===")
    stream = gen_event()
    for i in range(1000):
        name, action = next(stream)
        print(f"Event {i}: Player {name} did action {action}")
    ten_tuples = []
    for i in range(10):
        ten_tuples += [next(stream)]
    print(f"Built list of 10 events: {ten_tuples}")
    for consumed in consume_event(ten_tuples):
        print(f"Got event from list: {consumed}")
        print(f"Remains in list: {ten_tuples}")


if __name__ == "__main__":
    ft_data_stream()
