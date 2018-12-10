#!/usr/bin/env python3

import sys

file = sys.argv[1]
file = list(open("./{:s}".format(file), "r").readlines())
res = {}
for i in range(len(file)):
    if file[i].startswith("ACT I"):
        file = file[i:]
        break
for i in range(len(file)):
    file[i] = file[i].strip().lower()
    for word in file[i].split(" "):
        if word in res:
            res[word] += 1
        else:
            res[word] = 1
res = sorted(res.items())
print(res)
