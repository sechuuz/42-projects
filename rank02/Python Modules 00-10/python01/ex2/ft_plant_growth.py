class Plant:
    def __init__(self, name, height, age_val):
        self.name = name
        self.height = height
        self.age_val = age_val
        self.grow_rate = 0.8

    def grow(self):
        self.height += self.grow_rate
        self.height = round(self.height, 1)

    def age(self):
        self.age_val += 1

    def show(self):
        print(f"{self.name}: {self.height}cm, {self.age_val} days old")


if __name__ == "__main__":
    print("=== Garden Plant Growth ===")
    rose = Plant("Rose", 25, 30)
    initial_height = rose.height
    rose.show()
    for day in range(1, 8):
        rose.grow()
        rose.age()
        print(f"=== Day {day} ===")
        rose.show()
    print(f"Growth this week: "
          f"{round(rose.height - initial_height, 1)}cm")
