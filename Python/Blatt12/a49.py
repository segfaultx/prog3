#!/usr/bin/env python3

import sys
import re

amount_dict = {}
exp1 = re.compile(r'GET (/.+)+\.(png|gif|jpg)')
exp2 = re.compile(r'(png|gif|jpg)')
for line in open(sys.argv[1]):
    filetype = exp1.search(line)
    if filetype:
        file = exp2.search(filetype.group()).group()
    else:
        continue
    amount_dict[file] = amount_dict.get(file, 0) + 1

print(amount_dict)
