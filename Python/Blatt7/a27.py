#!/usr/bin/env python3

def dreh(lst):  # a27
    if not lst:
        return lst
    else:
        return [lst[-1]] + dreh(lst[:-1])


lst = [1, 2, 3, 4, 5]
print(lst)
print(dreh(lst))
