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
        if word in res:
            res[word] += 1
        elif word != '':
            res[word] = 1
for i in range(len(file)):
    file[i] = file[i].strip().lower()
    for letter in file[i]:
        if letter in alpha_res:
            alpha_res[letter] += 1
        elif letter.isalpha():  # if letter is alphabet add entry to alpha dict
            alpha_res[letter] = 1
res = sorted(res.items(), key=lambda x: tuple(reversed(x)), reverse=True)[:25]
alpha_res = sorted(alpha_res.items(), key=lambda x: tuple(reversed(x)), reverse=True)[:25]
print("\nWords:\n")
for word, amount in res:
    print("W:", word, "A:", amount)
print("\nLetters:\n")
for letter, amount in alpha_res:
    print("L:", letter, "A:", amount)
