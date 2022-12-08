Axel = int(input("Äpplen ?"))
Petra = int(input("Päron ?"))

if Axel == Petra:
    print("Petra")
elif Axel != Petra:
    axelSold = Axel * 7
    petraSold = Petra * 13

    if axelSold > petraSold:
        print("Axel")
    elif petraSold > axelSold:
        print("Petra")
    elif axelSold == petraSold:
        print("lika")


