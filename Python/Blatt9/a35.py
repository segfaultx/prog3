#!/usr/bin/env python3

dec = "eniastruhdlcmogkwbzfvpjxyq"
amount = {}
for line in open("a21-raeuberbrief.enc"):
    for letter in line.strip():
        if letter.isalpha() and letter.islower():
            amount[letter] = amount.get(letter, 0) + 1
out = "".join(
    dict(zip(list(dict(sorted(amount.items(), key=lambda x: (-x[1], x[0])))), dec)).get(z, z) for
    line in open("a21-raeuberbrief.enc") for z in line.strip())

print(out)
