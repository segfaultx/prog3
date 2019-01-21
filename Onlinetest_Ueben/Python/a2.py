#!/usr/bin/env python3


def statistik(filename):
    customers_dict = {}
    for line in open(filename):
        line = line.split(";")
        if line[1] in customers_dict[line[0]]:
            customers_dict.get(line[0])
        else:
            customers_dict[line[0]] = customers_dict.get(line[0], []).append((line[1], line[2]))


if __name__ == "__main__":
    # statistik("bestellungen-1.txt")
    print("Hallo" in ("Hallo", 1))
