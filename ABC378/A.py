import sys

input = sys.stdin.readline

tmp = [0 for _ in range(10)]

A = list(map(int, input().split()))

for i in A:
    tmp[i] += 1

ans = 0

for i in tmp:
    if i > 1:
        ans += i // 2

print(ans)
