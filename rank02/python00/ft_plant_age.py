def ft_plant_age():
    plant_age = int(input("Enter plant age in days: "))
    if plant_age > 60:
        response = "Plant is ready to harvest!"
    else:
        response = "Plant needs more time to grow."
    print(response)
