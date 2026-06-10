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


if __name__ == "__main__":
    print("=== Garden Security System ===")
    rose = Plant("Rose", 15, 10)
    rose.show()
    print("")
    rose.set_height(25)
    rose.set_age(30)
    print("")
    rose.set_height(-25)
    rose.set_age(-30)
    print("")
    rose.show()
