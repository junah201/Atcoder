import sys
from typing import List, Tuple, Dict
from collections import defaultdict, deque

input = sys.stdin.readline

N = int(input())

msg = ""

for i in range(N):
    if i % 3 == 2:
        msg += "x"
    else:
        msg += "o"

print(msg)
