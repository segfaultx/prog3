#!/usr/bin/env python3

dec = "eniastruhdlcmogkwbzfvpjxyq"
amount = {}
for letter in open("a21-raeuberbrief.enc").readline().strip():
    if letter.isalpha():
        amount[letter] = amount.get(letter, 0) + 1
print(amount)
print((list(dict(sorted(amount.items(), key=lambda x: tuple(reversed(x)), reverse=True)))))
print(dict(zip(list(dict(sorted(amount.items(), key=lambda x: tuple(reversed(x)), reverse=True))), dec)))
out = ["".join(
    dict(zip(list(dict(sorted(amount.items(), key=lambda x: tuple(reversed(x)), reverse=True))), dec)).get(z, z) for
    line in open("a21-raeuberbrief.enc") for z in line.strip())]

print(out)
