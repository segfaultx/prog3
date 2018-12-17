#!usr/bin/env Python3


def permutationen(elements):
    if len(elements) == 0:
        yield elements
    else:
        for i in range(len(elements)):
            yield [elements[i]] + list(permutationen(elements[i + 1:]))


for e in permutationen([1, 2, 3]):
    print(e)
