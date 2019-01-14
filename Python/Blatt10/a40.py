#!/usr/bin/env python3

from a39 import Messwert


class Messreihe:
    """Class to hold multiple tempvalues with timestamps"""

    def __init__(self, data=None):
        self._values = []
        if data:
            for item in data:
                self._values.append(Messwert(item))

    def __len__(self):
        return len(self._values)


if __name__ == "__main__":
    mr = Messreihe()
    mr2 = Messreihe(open("messwerte.csv"))
    print(mr, mr2, len(mr2))
