def ft_water_reminder():
    days = int(input("Days since last watering: "))
    if days > 2:
        response = "Water the plants!"
    else:
        response = "Plants are fine"
    print(response)
