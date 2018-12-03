def dreh(lst):
    if not lst:
        return lst
    else:
        curr = lst[-1]
        return [curr] + dreh(lst[:-1])

print(dreh([1,2,3,4,5]))
