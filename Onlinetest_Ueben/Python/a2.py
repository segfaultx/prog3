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
        print("{}:".format(key), end='')
        for k in sorted(customers_dict[key].keys()):
            print(" {}({})".format(k, customers_dict[key][k]), end='')
        print("")
