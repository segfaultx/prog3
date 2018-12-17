#!/usr/bin/env python3


print(["".join(dict(zip("wgsnqcdvmeyluzoabhrjfkxipt", "abcdefghijklmnopqrstuvwxyz")).get(z, z) for x in open("out.txt")
               for z in x).strip()])
