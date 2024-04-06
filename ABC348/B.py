import sys
from typing import List, Tuple, Dict
from collections import defaultdict, deque
input = sys.stdin.readline

N = int(input())
xy = [
    list(map(int, input().split()))
    for _ in range(N)
]

for i in xy:
    x, y = i

    ans = (0, 0)

    for j_idx, j in enumerate(xy):
        x2, y2 = j

        dist = abs(x - x2)**2 + abs(y - y2)**2

        ans = max(ans, (dist, -j_idx))

    print(-ans[1] + 1)
