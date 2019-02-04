#!/usr/bin/env python3

import re


def isHawaaian(word):
    vocals = "AEIOU"
    consonants = "HKLMNPW"
    word = word.upper()
    if word[-1] not in vocals:
        return False
    for i in range(len(word)):
        if word[i] not in consonants and word[i] not in vocals and word[i] != "'":
            return False
        if word[i] in consonants and word[i - 1] not in vocals:
            return False
        if word[i] == "'" and word[i - 1] in consonants:
            return False
    return True


hawaiaan_words = ["wikiwiki", "Wahine", "Aloha", "Hawai'i", "Humuhumunukunukuapua'a"]
for word in hawaiaan_words:
    print(isHawaaian(word))
non_hawaiian_words = ["Qui'juno", "Alaaf", "lekker", "Pu'kuuli", "ohamak'uluu"]
for word in non_hawaiian_words:
    print(isHawaaian(word))


def extractHi(iterable):
    for item in iterable:
        for word in item.split():
            word = re.match("[a-zA-z]+", word).group()
            if isHawaaian(word):
                yield word


for val in extractHi(["Eine Wahine sagt", "Maika’i no au!"]):
    print(val)
print("--------")
for val in extractHi( ("Hau’oli", "la hanau!", "Happy","Birthday!") ):
    print(val)