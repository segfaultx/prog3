#!/usr/bin/env python3


import re

print(re.match(r'(0[1-9]|[1-2]\d).(0[1-9]|1[1-2]).([1-2]\d{3})', "27.08.1009").group())

print(re.match(r'[1-9](\d{1,2}|\.\d{1,3})*,[0-9]{2} EUR', '123.45,50 EUR').group())

print(re.match(r'(\+\d{2}|0)[-/ ]?(\d{2}\d*[ /-]?\d)+\d*', '0170-576-312-66666-').group())
