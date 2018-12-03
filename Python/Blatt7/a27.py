#!/usr/bin/env python3


def dreh(lst):  # a27
    "Function to turn elements given list around"
    if not lst:
        return lst
    else:
        return [lst[-1]] + dreh(lst[:-1])


lst = [1, 2, 3, 4, 5]  # example lst
print(lst)  # print lst to show start order
print(dreh(lst))  # print list to show result of using dreh() func
