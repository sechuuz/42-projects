class Plant:
    def __init__(self, name, height, age_val):
        self.name = name
        self.height = height
        self.age_val = age_val

    def show(self):
        print(f"{self.name}: {self.height}cm, {self.age} days old")


if __name__ == "__main__":
    print("=== Garden Plant Registry ===")
    rose = Plant("Rose", 25, 30)
    sunflow = Plant("Sunflower", 80, 45)
    cactus = Plant("Cactus", 15, 120)
    plants = [rose, sunflow, cactus]
    for plant in plants:
        plant.show()
