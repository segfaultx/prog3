#!/usr/bin/env python3

from a40 import Messreihe


def enum(mr):
    cnt = 0
    for item in mr:
        yield cnt, item
        cnt += 1


if __name__ == "__main__":
    mr = Messreihe(open("../Blatt10/messwerte.csv"))
    for nr, messwert in enum(mr):
        print(nr, "->", messwert)
