import sys
import math

price = int(input("Priset N ?"))
count = 0
if price >= 11111:
    a = math.floor(price/11111)
    remainder = price - (11111*a)
    count += a
    if remainder == 0:
        print(count)
        sys.exit()
    elif remainder != 0:
        b = math.floor(remainder/1111)
        remainder2 = remainder - (1111*b)
        count += b
        if remainder2 == 0:
            print(count)
            sys.exit()
        elif remainder2 != 0:
            c = math.floor(remainder2/111)
            remainder3 = remainder2 - (111*c)
            count += c
            if remainder3 == 0:
                print(count)
                sys.exit()
            elif remainder3 != 0:
                d = math.floor(remainder3/11)
                remainder4 = remainder3 - (11*d)
                count += d
                if remainder4 == 0:
                    print(count)
                    sys.exit()
                elif remainder4 != 0:
                    e = math.floor(remainder4/1)
                    count += e
                    print(count)
                    sys.exit()
if price >= 1111:
    b = math.floor(price/1111)
    remainder2 = price - (1111 * b)
    count += b
    if remainder2 == 0:
        print(count)
        sys.exit()
    elif remainder2 != 0:
        c = math.floor(remainder2 / 111)
        remainder3 = remainder2 - (111 * c)
        count += c
        if remainder3 == 0:
            print(count)
            sys.exit()
        elif remainder3 != 0:
            d = math.floor(remainder3 / 11)
            remainder4 = remainder3 - (11 * d)
            count += d
            if remainder4 == 0:
                print(count)
                sys.exit()
            elif remainder4 != 0:
                e = math.floor(remainder4 / 1)
                count += e
                print(count)
                sys.exit()
if price >= 111:
    c = math.floor(price/111)
    remainder3 = price - (111 * c)
    count += c
    if remainder3 == 0:
        print(count)
        sys.exit()
    elif remainder3 != 0:
        d = math.floor(remainder3 / 11)
        remainder4 = remainder3 - (11 * d)
        count += d
        if remainder4 == 0:
            print(count)
            sys.exit()
        elif remainder4 != 0:
            e = math.floor(remainder4 / 1)
            count += e
            print(count)
            sys.exit()
if price >= 11:
    d = math.floor(price/ 11)
    remainder4 = price - (11 * d)
    count += d
    if remainder4 == 0:
        print(count)
        sys.exit()
    elif remainder4 != 0:
        e = math.floor(remainder4 / 1)
        count += e
        print(count)
        sys.exit()
if price >= 1:
    e = math.floor(price/ 1)
    count += e
    print(count)
