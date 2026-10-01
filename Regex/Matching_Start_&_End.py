Regex_Pattern = r"^\d\S\S\S\S\.$"	# Do not delete 'r'.

import re

print(str(bool(re.search(Regex_Pattern, input()))).lower())
