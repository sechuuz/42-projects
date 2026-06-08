import sys


def ft_inventory_system() -> None:
    print("=== Inventory System Analysis ===")
    inventory = {}
    for arg in sys.argv[1:]:
        item = arg.split(":")
        if len(item) != 2:
            print(f"Error - invalid parameter '{arg}'")
            continue
        elif item[0] in inventory:
            print(f"Redundant item '{item[0]}' - discarding")
            continue
        try:
            inventory[item[0]] = int(item[1])
        except ValueError as err:
            print(f"Quantity error for '{item[0]}': {err}")
    if len(sys.argv[1:]) == 0 or len(inventory) == 0:
        print("No inventory provided!")
        return
    print(f"Got inventory: {inventory}")
    item_list = list(inventory.keys())
    print(f"Item list: {item_list}")
    total_quantity = sum(inventory.values())
    print(f"Total quantity of the {len(item_list)} items: {total_quantity}")
    most_ab = item_list[0]
    least_ab = item_list[0]
    for k in inventory:
        if inventory[k] != 0:
            percentage = (inventory[k] / total_quantity) * 100
        else:
            percentage = 0
        print(f"Item {k} represents {percentage:.1f}%")
        if inventory[k] > inventory[most_ab]:
            most_ab = k
        if inventory[k] < inventory[least_ab]:
            least_ab = k
    print(f"Item most abundant: {most_ab} with quantity {inventory[most_ab]}")
    print(f"Item least abundant: {least_ab} "
          f"with quantity {inventory[least_ab]}")
    inventory.update([("magic_item", 1)])
    print(f"Updated inventory: {inventory}")


if __name__ == "__main__":
    ft_inventory_system()
