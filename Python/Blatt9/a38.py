#!/usr/bin/env python3


def permutationen(elements):
    if len(elements) == 0:  # base case, empty list does not have any more permutations
        yield elements
    else:
        for ele in elements:
            perm = list(elements)  # copy list
            perm.remove(ele)  # remove current item from list
            for perm in permutationen(perm):  # iterate over permutations of remaining list
                yield [ele] + perm  # yield current permutation


for e in permutationen([1, 2, 3]):  # iterate over generator output
    print(e)
