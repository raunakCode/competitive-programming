personnummer = list(input("Nummer ?"))

if personnummer[6] == "-":
    centuryCheck = [personnummer[i] for i in [0,1]]
    if int("".join(centuryCheck)) > 20:
        newPersonnummer = ["1","9"]
        personnummer.pop(6)
        for i in personnummer:
            newPersonnummer.append(i)
        newPersonnummer = int("".join(newPersonnummer))
        print(int(newPersonnummer))
    elif int("".join(centuryCheck)) < 20:
        newPersonnummer = ["2","0"]
        personnummer.pop(6)
        for i in personnummer:
            newPersonnummer.append(i)
        newPersonnummer = int("".join(newPersonnummer))
        print(int(newPersonnummer))
elif personnummer[6] == "+":
    centuryCheck = [personnummer[i] for i in [0, 1]]
    if int("".join(centuryCheck)) > 20:
        newPersonnummer = ["1","8"]
        personnummer.pop(6)
        for i in personnummer:
            newPersonnummer.append(i)
        newPersonnummer = int("".join(newPersonnummer))
        print(int(newPersonnummer))
    elif int("".join(centuryCheck)) < 20:
        newPersonnummer = ["1","9"]
        personnummer.pop(6)
        for i in personnummer:
            newPersonnummer.append(i)
        newPersonnummer = int("".join(newPersonnummer))
        print(int(newPersonnummer))







