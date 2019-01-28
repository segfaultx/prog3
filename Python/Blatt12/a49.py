#!/usr/bin/env python3

import re
import sys

for line in sys.stdin:
    print(re.sub(r'\w+', lambda x: "".join(reversed(list(x.group())) if x.group().isalpha() else x.group()), line))
