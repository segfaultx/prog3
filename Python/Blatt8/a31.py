#!/usr/bin/env python3

import sys

file = sys.argv[1]
print("./{:s}".format(file))
file = list(open("./{:s}".format(file), "r").readlines())
data = []
res = {}
for i in range(len(file)):
    if file[i].startswith("ACT I"):
        data = file[i:]
        break
for i in range(len(data)):
    data[i] = data[i].strip().lower()
    for word in data[i].split(" "):
        if word in res:
            res[word] += 1
        else:
            res[word] = 1
res = sorted(res.items())
print(res)
