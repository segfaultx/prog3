#!/usr/bin/env python3


class Messwert:
    """Class to hold temperature timestampts data"""

    def __init__(self, line, value=-99.0):
        if value != -99:
            self.time = line
            self.temp = float(value)
        else:
            self.time = line.split(",")[0]
            self.temp = float(line.split(",")[1])

    def __repr__(self):
        return "Messwert('{}',{})".format(self.time, self.temp)

    def __eq__(self, other):
        if isinstance(other, self.__class__):
            if self.time == other.time and self.temp == other.temp:
                return True
            return False

    def __lt__(self, other):
        return self.time < other.time

    def __gt__(self, other):
        return self.time > other.time

    def __ge__(self, other):
        return self.time >= other.time

    def __le__(self, other):
        return self.time <= other.time

    def __key(self):
        return self.time, self.temp

    def __hash__(self):
        return hash(self.__key())


if __name__ == "__main__":
    mw = Messwert("2019-01-11 17:45:01.356640,19.5")  # 2
    mw2 = Messwert("2019-01-12 17:45:01.356640,19.5")  # 3
    mw3 = Messwert("2019-01-12 17:49:01.356640,19.5")  # 4
    mw4 = Messwert("2019-01-13 17:45:01.356640,19.5")  # 5
    mw5 = Messwert("2019-01-09 17:45:01.356640,19.5")  # 1
    mw6 = Messwert("2019-01-15 17:45:01.356640,19.5")  # 6
    mw7 = Messwert("2019-01-16 17:45:01.356640,19.5")  # 7
    print(mw)
    print(eval(repr(mw)) == mw)
    lst = [mw7, mw, mw5, mw2, mw4, mw3, mw6]
    print(lst)
    print(sorted(lst))

    print(set(lst))
