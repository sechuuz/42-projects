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
        print(f"{self.name}: {self.height:.1f}cm, {self.age_val} days old")


if __name__ == "__main__":
    print("=== Plant Factory Output ===")
    plants = [
        Plant("Rose", 25, 30),
        Plant("Oak", 200, 365),
        Plant("Cactus", 5, 90),
        Plant("Sunflower", 80, 45),
        Plant("Fern", 15, 120)
    ]
    for plant in plants:
        print("Created: ", end="")
        plant.show()
