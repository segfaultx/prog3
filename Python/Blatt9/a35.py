#!/usr/bin/env python3

dec = "eniastruhdlcmogkwbzfvpjxyq"
amount = {}
for letter in open("a21-raeuberbrief.enc").readline().strip():
    if letter.isalpha():
        amount[letter] = amount.get(letter, 0) + 1
print(amount)  # amount test
print(dict(sorted(amount.items(), key=lambda x: (-x[1], x[0]))))  # sort test
print(dict(zip(list(dict(sorted(amount.items(), key=lambda x: (-x[1], x[0])))), dec)))  # dec dict test
out = ["".join(
    dict(zip(list(dict(sorted(amount.items(), key=lambda x: (-x[1], x[0])))), dec)).get(z, z) for
    line in open("a21-raeuberbrief.enc") for z in line.strip())]

print(out)
