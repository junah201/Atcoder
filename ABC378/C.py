import sys

input = sys.stdin.readline


cache = {}

N = int(input())
A = list(map(int, input().split()))

ans = [
    "-1" for _ in range(N)
]

for idx, value in enumerate(A):
    if value in cache:
        ans[idx] = cache[value]

    cache[value] = str(idx + 1)

print(" ".join(ans))
