#!/usr/bin/env python3

from a40 import Messreihe

mr = Messreihe(open("messwerte.csv"))
print("Länge", len(mr))
print("Max", max([val.temp for val in mr]))
print("Min", min([val.temp for val in mr]))
print("Temp>33°", [mw for mw in mr if mw.temp > 33])
print(len([mw for mw in mr["2017"] if mw.temp > 26]))
print([mw for mw in mr if int(mw.temp) == 17][-1])
print(sum(mw.temp for mw in [mw for mw in mr["2017-1"]])/len(mr["2017-1"]))
