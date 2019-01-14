#!/usr/bin/env python3

from a39 import Messwert


class Messreihe:
    """Class to hold multiple tempvalues with timestamps"""

    def __init__(self, data=None):
        if data:
            self.values = [Messwert(val) for val in data]
        else:
            self.values = []

    def __len__(self):
        return len(self.values)

    def __add__(self, other):
        if isinstance(other, self.__class__):
            for val in other.values:
                self.add(val)
        else:
            raise TypeError

    def add(self, values):
        for val in values:
            if val not in self.values:
                self.values.append(val)
            else:
                raise ValueError

    def __getitem__(self, n):
        if isinstance(n, slice):
            return self.values[n.start:n.stop:n.step]
        if isinstance(n, str):
            return [mw for mw in self.values if n in mw.time]
        return self.values[n]

    def __mr_iter(self):
        for mw in sorted(self.values):
            yield mw

    def __iter__(self):
        return self.__mr_iter()


if __name__ == "__main__":
    mr = Messreihe()
    mr2 = Messreihe(open("messwerte.csv"))
    print(mr, "|", mr2, "|", len(mr2), "|", mr2[100], "|", mr2[1:10])
    for item in mr2[:10]:
        print(item)
