regex_pattern = r"^\S{3}\.\S{3}\.\S{3}\.\S{3}$"

import re
import sys

test_string = input()

match = re.match(regex_pattern, test_string) is not None

print(str(match).lower())
