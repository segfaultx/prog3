#!/usr/bin/env python3

def devocalize(s):  # A25
    "Entfernt unnötige Vokale aus gegebenem String"
    res = ""
    for ele in s:
        if not ele in "aeiouAEIOU":
            res += ele
    return res


if __name__ == "__main__": # if name == main to ensure a25 can be used as module
    print(devocalize("Das ist ein Baerenspass."))
    help(devocalize)  # A26
