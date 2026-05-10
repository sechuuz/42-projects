def ft_count_harvest_recursive():
    days = int(input("Days until harvest: "))

    def count_recurse(i):
        if i > days:
            return
        print(f"Day {i}")
        count_recurse(i + 1)

    count_recurse(1)
    print("Harvest time!")
