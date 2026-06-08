def secure_archive(file_name: str,
                   op: str = "r",
                   content: str = "") -> tuple[bool, str]:
    try:
        if op == "r":
            with open(file_name, op) as file:
                content = file.read()
                return (True, content)
        elif op == "w":
            with open(file_name, op) as file:
                file.write(content)
                return (True, "Content successfully written to file")
        return (False, "Invalid Arguments")
    except Exception as err:
        return (False, f"{err}")


def ft_vault_security() -> None:
    print("=== Cyber Archives Security ===")
    print()
    print("Using 'secure_archive' to read from a nonexistent file:")
    print(secure_archive("/not/existing/file", "r"))
    print()
    print("Using 'secure_archive' to read from an inaccessible file:")
    print(secure_archive("/etc/shadow", "r"))
    print()
    print("Using 'secure_archive' to read from a regular file:")
    copy = secure_archive("ancient_fragment.txt", "r")
    print(copy)
    print()
    print("Using 'secure_archive' to write previous content to a new file:")
    print(secure_archive("newfile", "w", copy[1]))


if __name__ == "__main__":
    ft_vault_security()
