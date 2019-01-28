#!/usr/bin/env python3

import sys
import re

amount_dict = {}
exp1 = re.compile(
    r'(?P<ipaddress>\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}).*(?P<time>\d{2}:\d{2}:\d{2}).*(?P<get>GET (/.+?)(\.(?P<extension>png|gif|jpg))?) HTTP')
for line in open(sys.argv[1]):
    filetype = exp1.match(line)
    if filetype:
        print(filetype.groupdict())

print(amount_dict)

wip = r'(\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3})[ -]+\[[^:]+:(\d{2}:\d{2}:\d{2})[^\]]*\]\s"(GET (/.+?)(\.(png|gif|jpg))?) HTTP'