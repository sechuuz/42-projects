def print_day(num):
    if (num == 0):
        return 0
    print_day(num - 1)
    print(f"Day {num}")


def ft_count_harvest_recursive():
    count = int(input("Days until harvest: "))
    print_day(count)
    print("Harvest time!")
