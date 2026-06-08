class Plant:
    def __init__(self, name, height, age_val):
        self.name = name
        self.grow_rate = 0.8
        self._height = height
        self._age_val = age_val

    def set_height(self, new):
        if new < 0:
            print(f"{self.name}: Error, height can't be negative")
            print("Height update rejected")
        else:
            self._height = new
            print(f"Height updated: {self._height}cm")

    def set_age(self, new):
        if new < 0:
            print(f"{self.name}: Error, age can't be negative")
            print("Age update rejected")
        else:
            self._age_val = new
            print(f"Age updated: {self._age_val} days")

    def get_height(self):
        return self._height

    def get_age(self):
        return self._age_val

    def grow(self):
        self._height += self.grow_rate
        self._height = round(self._height, 1)

    def age(self):
        self._age_val += 1

    def show(self):
        print(f"{self.name}: {self._height:.1f}cm, {self._age_val} days old")


class Flower(Plant):
    def __init__(self, name, height, age_val, color):
        super().__init__(name, height, age_val)
        self.color = color
        self.has_bloomed = False

    def bloom(self):
        self.has_bloomed = True

    def show(self):
        super().show()
        print(f" Color: {self.color}")
        if not self.has_bloomed:
            print(f" {self.name} has not bloomed yet")
        else:
            print(f" {self.name} is blooming beautifully!")


class Tree(Plant):
    def __init__(self, name, height, age_val, trunk_diameter):
        super().__init__(name, height, age_val)
        self.trunk_diameter = trunk_diameter

    def produce_shade(self):
        print(f"Tree {self.name} now produces a shade of "
              f"{self._height:.1f}cm long and "
              f"{self.trunk_diameter:.1f}cm wide.")

    def show(self):
        super().show()
        print(f" Trunk diameter: {self.trunk_diameter:.1f}cm")


class Vegetable(Plant):
    def __init__(self, name, height, age_val, harvest_season,
                 nutritional_value):
        super().__init__(name, height, age_val)
        self.harvest_season = harvest_season
        self.nutritional_value = nutritional_value
        self.grow_rate = 2.1

    def grow(self):
        self._height += self.grow_rate
        self._height = round(self._height, 1)
        self.nutritional_value += 1

    def show(self):
        super().show()
        print(f" Harvest Season: {self.harvest_season}")
        print(f" Nutritional Value: {self.nutritional_value}")


if __name__ == "__main__":
    print("=== Garden Plant Types ===")
    print("=== Flower")
    rose = Flower("Rose", 15, 10, "red")
    rose.show()
    print("[asking the rose to bloom]")
    rose.bloom()
    rose.show()
    print("\n=== Tree")
    oak = Tree("Oak", 200, 365, 5)
    oak.show()
    print("[asking the oak to produce shade]")
    oak.produce_shade()
    print("\n=== Vegetable")
    tomato = Vegetable("Tomato", 5, 10, "April", 0)
    tomato.show()
    print("[make tomato grow and age for 20 days]")
    for i in range(1, 21):
        tomato.age()
        tomato.grow()
    tomato.show()
