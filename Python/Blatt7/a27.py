def dreh(lst): #a27
    if not lst:
        return lst
    else:
        curr = lst[-1]
        return [curr] + dreh(lst[:-1])
lst=[1,2,3,4,5]
print(lst)
print(dreh(lst))
