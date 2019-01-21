#!/usr/bin/env python3


def statistik(filename):
    customers_dict = {}
    for line in open(filename):
        line = line.split(";")
        if line[0] in customers_dict.keys():
            customers_dict[line[0]][line[1]] = customers_dict[line[0]].get(line[1], 0) + int(line[2])
        else:
            customers_dict[line[0]] = customers_dict.get(line[0], {})
            customers_dict[line[0]][line[1]] = customers_dict[line[0]].get(line[0], int(line[2]))
    for key in sorted(customers_dict):
        print(f'{key}', " ".join([f'{k}({v})' for k, v in sorted(customers_dict[key].items())]))


if __name__ == "__main__":
    print("Test 1")
    statistik("bestellungen-1.txt")
    print("Test 2")
    statistik("bestellungen-2.txt")
    print("Test 3")
    statistik("bestellungen-3.txt")
    print("Test 4")
    statistik("bestellungen-4.txt")
