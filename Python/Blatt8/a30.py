#!/usr/bin/env python3


def ggT(x, y):
    """Recursive function to find shared divider"""
    if x == y:
        return x
    if x > y:
        return ggT(x - y, y)
    return ggT(y, x)


def ggT2(x, y):
    """Iterative function to find shared divider"""
    while x % y != 0:  # while x module y is not 0 continue calculating divider
        if x < y:
            x, y = y, x
        x = x % y
    return y


def ggTi(x, *y):
    curr_divider_val = ggT2(x, y[0])  # calculate first divider
    for ele in y[1:]:  # for each ele in y, excluding first calculate new divider
        curr_divider_val = ggT2(curr_divider_val, ele)
    return curr_divider_val


# tests recursive
print("Recursive:")
print(ggT(10, 30))
print(ggT(20, 30))
print(ggT(2, 5))
print(ggT(8, 6))
print(ggT(7, 3))

# tests iterative
print("Iterative:")
print(ggT2(10, 30))
print(ggT2(20, 30))
print(ggT2(2, 5))
print(ggT2(8, 6))
print(ggT2(7, 3))

data = list(open("./a30-ggts.dat", "r"))
sum_dividers = 0
count = 0

for i in range(len(data)):  # iterate over data and calulcate dividers for each even i>=0
    if i % 2 == 0:
        sum_dividers += ggT2(int(data[i]), int(data[i + 1]))
        count += 1

print("Average of all dividers is {:10f}".format(sum_dividers / count))

print("Test ggTi:")
print(ggTi(10, 80, 20, 75))
print(ggTi(17, 4))
print(ggTi(7, 2, 2, 1, 20, 11))
