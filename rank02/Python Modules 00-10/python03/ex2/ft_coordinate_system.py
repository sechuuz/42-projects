import math


def get_player_pos() -> tuple[float, float, float]:
    while True:
        player_pos = input("Enter new coordinates"
                           " as floats in format 'x,y,z': ").split(",")
        coords = []
        if len(player_pos) != 3:
            print("Invalid syntax")
        else:
            try:
                for point in player_pos:
                    coords += [float(point)]
                return (coords[0], coords[1], coords[2])
            except ValueError as err:
                print(f"Error on parameter '{point}': {err}")


def ft_coordinate_system() -> None:
    print("=== Game Coordinate System ===")
    print()
    print("Get a first set of coordinates")
    first_set = get_player_pos()
    print(f"Got a first tuple: {first_set}")
    print(f"It includes: X={first_set[0]:.1f}, "
          f"Y={first_set[1]:.1f}, Z={first_set[2]:.1f}")
    dis_to_center = first_set[0] ** 2
    dis_to_center += first_set[1] ** 2
    dis_to_center += first_set[2] ** 2
    dis_to_center = math.sqrt(dis_to_center)
    print(f"Distance to center: {dis_to_center:.4f}")
    print()
    print("Get a second set of coordinates")
    second_set = get_player_pos()
    dis_to_center = (second_set[0] - first_set[0]) ** 2
    dis_to_center += (second_set[1] - first_set[1]) ** 2
    dis_to_center += (second_set[2] - first_set[2]) ** 2
    dis_to_center = math.sqrt(dis_to_center)
    print(f"Distance between the 2 sets of coordinates: "
          f"{dis_to_center:.4f}")


if __name__ == "__main__":
    ft_coordinate_system()
