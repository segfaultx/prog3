#!/usr/bin/env python3

lst = list(range(0, 101))  # create list with range 0-100
print(lst[:11])  # print first 10 elements of list
print(lst[-11:])  # print last 11 elements of list
print(lst[0::10])  # print every 10th element of list
print(lst[len(lst) // 2])  # print middle element of list
print(lst[5:-5:3])  # print every 3rd element starting at element no. 5 and without last 5
