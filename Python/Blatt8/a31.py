#!/usr/bin/env python3

import sys

file = sys.argv[1]
res = {}
alpha_res = {}
start_dicts = False
for ele in open("./{:s}".format(file), "r").readlines():
    if ele.startswith("ACT I"):
        start_dicts = True
    if start_dicts:
        ele = ele.strip().lower()  # reduce every line to lowercase, so we can properly count them
        for letter in ele:
            if letter.isalpha():
                alpha_res[letter] = alpha_res.get(letter, 0) + 1
        for word in ele.split(" "):
            if word != "":
                res[word] = res.get(word, 0) + 1  # get value at given key, 0 default and add 1
res = sorted(res.items(), key=lambda x: tuple(reversed(x)), reverse=True)[:25]
alpha_res = sorted(alpha_res.items(), key=lambda x: tuple(reversed(x)), reverse=True)[:25]
print("\nWords:\n")
for word, amount in res:
    print("W:", word, "A:", amount)
print("\nLetters:\n")
for letter, amount in alpha_res:
    print("L:", letter, "A:", amount)
