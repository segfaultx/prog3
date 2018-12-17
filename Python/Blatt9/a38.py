#!usr/bin/env Python3


def permutationen(elements):
    if len(elements) == 0:
        yield elements
    else:
        for i in range(len(elements)):
            perm = list(elements)
            perm.remove(elements[i])
            for perm in permutationen(perm):
                yield [elements[i]] + perm


for e in permutationen([1, 2, 3]):
    print(e)
