import sys
from itertools import combinations

N, M = map(int, sys.stdin.readline().split())

S = []

tmp = []
for i in range(1, M + 1):
    tmp.extend(list(combinations(range(1, M + 1), i)))

for _ in range(M):
    sys.stdin.readline()
    S.append(set(map(int, sys.stdin.readline().split())))

ans = 0

for i in tmp:
    tmp_set = set()
    for j in i:
        tmp_set |= S[j - 1]

    if len(tmp_set) == N:
        ans += 1

print(ans)
