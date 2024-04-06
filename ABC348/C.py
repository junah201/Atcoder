import sys
from typing import List, Tuple, Dict
from collections import defaultdict, deque
input = sys.stdin.readline

N = int(input())

AC = [
    list(map(int, input().split()))
    for _ in range(N)
]

ans = {}

for i in AC:
    a, c = i

    if ans.get(c) is None:
        ans[c] = a
    elif ans.get(c) > a:
        ans[c] = a


print(max(ans.values()))
