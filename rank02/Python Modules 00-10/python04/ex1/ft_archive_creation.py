import sys


def ft_archive_creation() -> None:
    if len(sys.argv) < 2:
        print(f"Usage: {sys.argv[0]} <file>")
        return
    print("=== Cyber Archives Recovery & Preservation ===")
    print(f"Accessing file '{sys.argv[1]}'")
    try:
        f = open(sys.argv[1], "r")
        f_old = f.read()
        print("---\n")
        print(f_old)
        print("\n---")
        print(f"File '{sys.argv[1]}' closed.")
        f.close()
        f_new = ""
        for char in f_old:
            if char == "\n":
                f_new = f_new + "#\n"
            else:
                f_new = f_new + char
        if len(f_old) > 0:
            if f_old[len(f_old) - 1] != "\n":
                f_new = f_new + "#"
        print()
        print("Transform data: ")
        print("---\n")
        print(f_new)
        print("\n---")
        f_name = input("Enter new file name (or empty): ")
        if f_name:
            print(f"Saving data to '{f_name}'")
            with open(f_name, "w") as n:
                n.write(f_new)
            print(f"Data saved in file '{f_name}'")
        else:
            print("Not saving data.")
    except (FileNotFoundError, PermissionError) as err:
        print(f"Error opening file '{sys.argv[1]}': {err}")
        return


if __name__ == "__main__":
    ft_archive_creation()
