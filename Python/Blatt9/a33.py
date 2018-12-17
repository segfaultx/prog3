#!/usr/bin/env python3


# I

print([i ** 3 for i in range(1, 11)])

# II

print([z for z in range(2, 123) if 123 % z == 0])
print([z for z in range(2, 12345) if 12345 % z == 0])
print([z for z in range(2, 123456) if 123456 % z == 0])

# III

print([prime for prime in range(10000, 10100) if not [i for i in range(2, prime) if prime % i == 0]])

# B

# I
print(list(map(lambda x: x ** 3, range(1, 11))))

# II

print(list(filter(lambda x: 123 % x == 0, range(2, 123))))
print(list(filter(lambda x: 12345 % x == 0, range(2, 12345))))
print(list(filter(lambda x: 123456 % x == 0, range(2, 123456))))


# III

def prime(x):
    for i in range(2, x):
        if x % i == 0:
            return False
    return True


print(list(filter(prime, range(10001, 10100))))
