class Plant:
    def __init__(self, name, height, age_val):
        self.name = name
        self.grow_rate = 8
        self._height = height
        self._age_val = age_val
        self.stats = self.Stats()

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
        self.stats.grow_called()

    def age(self):
        self._age_val += 1
        self.stats.age_called()

    def show(self):
        print(f"{self.name}: {self._height:.1f}cm, {self._age_val} days old")
        self.stats.show_called()

    @classmethod
    def create_anon(cls):
        return cls("Unknown plant", 0, 0)

    @staticmethod
    def year_check(days):
        if (days > 365):
            return True
        else:
            return False

    class Stats:
        def __init__(self):
            self._grow_calls = 0
            self._age_calls = 0
            self._show_calls = 0

        def grow_called(self):
            self._grow_calls += 1

        def age_called(self):
            self._age_calls += 1

        def show_called(self):
            self._show_calls += 1

        def display(self):
            print(f"{self._grow_calls} grow, "
                  f"{self._age_calls} age, "
                  f"{self._show_calls} show")


class Flower(Plant):
    def __init__(self, name, height, age_val, color="Unknown"):
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
    def __init__(self, name, height, age_val, trunk_diameter=0):
        super().__init__(name, height, age_val)
        self.trunk_diameter = trunk_diameter

    def produce_shade(self):
        print(f"Tree {self.name} now produces a shade of "
              f"{self._height:.1f}cm long and "
              f"{self.trunk_diameter:.1f}cm wide.")
        self.stats.shade_called()

    class Stats(Plant.Stats):
        def __init__(self):
            super().__init__()
            self._shade_calls = 0

        def shade_called(self):
            self._shade_calls += 1

        def display(self):
            super().display()
            print(f" {self._shade_calls} shade")


class Vegetable(Plant):
    def __init__(self, name, height, age_val, harvest_season="Unknown",
                 nutritional_value=0):
        super().__init__(name, height, age_val)
        self.harvest_season = harvest_season
        self.nutritional_value = nutritional_value

    def grow(self):
        super().grow()
        self.nutritional_value += 1

    def show(self):
        super().show()
        print(f" Harvest Season: {self.harvest_season}")
        print(f" Nutritional Value: {self.nutritional_value}")


class Seed(Flower):
    def __init__(self, name, height, age_val, color="Unknown"):
        super().__init__(name, height, age_val, color)
        self.seed_amt = 0
        self.grow_rate = 30

    def age(self):
        self._age_val += 20
        self.stats.age_called()

    def bloom(self):
        super().bloom()
        self.seed_amt += 42

    def show(self):
        super().show()
        print(f" Seeds: {self.seed_amt}")


def show_stats(plant):
    print(f"[statistics for {plant.name}]")
    print("Stats: ", end="")
    plant.stats.display()


if __name__ == "__main__":
    print("=== Garden statistics ===")
    print("=== Check year-old")
    print("Is 30 days more than a year? -> "
          f"{Plant.year_check(30)}")
    print("Is 400 days more than a year? -> "
          f"{Plant.year_check(400)}")
    print()
    print("=== Flower")
    rose = Flower("Rose", 15, 10, "red")
    rose.show()
    show_stats(rose)
    print("[asking the rose to grow and bloom]")
    rose.bloom()
    rose.grow()
    rose.show()
    show_stats(rose)
    print()
    print("=== Tree")
    oak = Tree("Oak", 200, 365, 5)
    oak.show()
    show_stats(oak)
    print("[asking the oak to produce shade]")
    oak.produce_shade()
    show_stats(oak)
    print()
    print("=== Seed")
    sunflower = Seed("Sunflower", 80, 45, "yellow")
    sunflower.show()
    print("[make sunflower grow, age and bloom]")
    sunflower.grow()
    sunflower.age()
    sunflower.bloom()
    sunflower.show()
    show_stats(sunflower)
    print()
    print("=== Anonymous")
    anon = Plant.create_anon()
    anon.show()
    show_stats(anon)
