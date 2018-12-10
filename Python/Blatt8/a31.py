#!/usr/bin/env python3

import sys

file = sys.argv[1]
file = list(open("./{:s}".format(file), "r").readlines())
res = {}
alpha_res = {}
for i in range(len(file)):
    if file[i].startswith("ACT I"):  # once we've found the line starting with "ACT I" copy over data and leave loop
        file = file[i:]
        break
for i in range(len(file)):
    file[i] = file[i].strip().lower()  # reduce every line to lowercase, so we can properly count them
    for word in file[i].split(" "):
        res[word] = res.get(word, 0) + 1  # get value at given key, 0 default and add 1
for i in range(len(file)):
    file[i] = file[i].strip().lower()
    for letter in file[i]:
        alpha_res[letter] = alpha_res.get(letter, 0) + 1
res = sorted(res.items(), key=lambda x: tuple(reversed(x)), reverse=True)[:25]
alpha_res = sorted(alpha_res.items(), key=lambda x: tuple(reversed(x)), reverse=True)[:25]
print("\nWords:\n")
for word, amount in res:
    print("W:", word, "A:", amount)
print("\nLetters:\n")
for letter, amount in alpha_res:
    print("L:", letter, "A:", amount)
