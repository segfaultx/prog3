#!/usr/bin/env python3

from a39 import Messwert


class Messreihe:
    """Class to hold multiple tempvalues with timestamps"""

    def __init__(self, data=None):
        self.values = []
        if data:
            for item in data:
                self.values.append(Messwert(item))

    def __len__(self):
        return len(self.values)

    def __add__(self, other):
        if isinstance(other, self.__class__):
            self.values += other.values
        else:
            raise TypeError

    def add(self, values):
        for item in values:
            self.values.append(item)

    def __getitem__(self, n):
        if isinstance(n, slice):
            return self.values[n.start:n.stop:n.step]
        return self.values[n]


if __name__ == "__main__":
    mr = Messreihe()
    mr2 = Messreihe(open("messwerte.csv"))
    print(mr, mr2, len(mr2))
