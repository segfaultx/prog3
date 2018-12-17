#!/usr/bin/env python3

import glob
import os

# lists 3 biggest files ending with .conf
print(sorted([item for item in glob.glob("/etc/*.conf")], key=lambda x: os.path.getsize(x), reverse=True)[:3])
