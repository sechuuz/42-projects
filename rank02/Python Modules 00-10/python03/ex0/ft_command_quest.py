import sys


def ft_command_quest() -> None:
    print("=== Command Quest ===")
    print(f"Program name: {sys.argv[0]}")
    args = sys.argv[1:]
    argc = len(sys.argv)
    if not args:
        print("No arguments provided!")
    else:
        print(f"Arguments received: {argc - 1}")
        count = 1
        for arg in sys.argv[1:]:
            print(f"Argument {count}: {arg}")
            count += 1
    print(f"Total arguments: {argc}")


if __name__ == "__main__":
    ft_command_quest()
