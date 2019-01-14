#!/usr/bin/env python3


class Messwert:
    """Class to hold temperature timestampts data"""

    def __init__(self, line, value=-99.0):
        if value != -99:
            self.time = line
            self.temp = value
        else:
            self.time = line.split(",")[0]
            self.temp = line.split(",")[1]

    def __repr__(self):
        return "Messwert({},{})".format(self.time, self.temp)

    def __eq__(self, other):
        if self.temp != other.temp:
            return False
        if self.time != other.time:
            return False
        return True


mw = Messwert("2019-01-11 17:45:01.356640,19.5")
print(eval(repr(mw)) == mw)
