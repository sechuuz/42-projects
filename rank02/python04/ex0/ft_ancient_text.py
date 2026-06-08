import sys


def ft_ancient_text() -> None:
    if len(sys.argv) < 2:
        print(f"Usage: {sys.argv[0]} <file>")
        return
    print("=== Cyber Archives Recovery ===")
    print(f"Accessing file '{sys.argv[1]}'")
    try:
        f = open(sys.argv[1], "r")
        print("---\n")
        print(f.read())
        print("\n---")
        print(f"File '{sys.argv[1]}' closed.")
        f.close()
    except (FileNotFoundError, PermissionError) as err:
        print(f"Error opening file '{sys.argv[1]}': {err}")
        return


if __name__ == "__main__":
    ft_ancient_text()
