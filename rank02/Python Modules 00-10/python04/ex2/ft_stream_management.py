import sys


def ft_stream_management() -> None:
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
        f.close()
        print(f"File '{sys.argv[1]}' closed.")
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
        print("Enter new file name (or empty): ")
        sys.stdout.flush()
        f_name = sys.stdin.readline()
        if len(f_name) > 0 and f_name[len(f_name) - 1] == "\n":
            f_name = f_name[:-1]
        if f_name:
            print(f"Saving data to '{f_name}'")
            try:
                n = open(f_name, "w")
                n.write(f_new)
                n.close()
                print(f"Data saved in file '{f_name}'")
            except Exception as err:
                sys.stderr.write("[STDERR] Error opening file "
                                 f"'{f_name}': {err}\n")
                print("Data not saved.")
        else:
            print("Not saving data.")
    except Exception as err:
        sys.stderr.write("[STDERR] Error opening file "
                         f"'{sys.argv[1]}': {err}\n")
        return


if __name__ == "__main__":
    ft_stream_management()
