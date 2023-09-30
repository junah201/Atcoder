import sys
input = sys.stdin.readline

INF = 10 ** 9 + 7

N, M = map(int, input().split())
A = list(map(int, input().split()))

ans = [INF] * (N + 1)

idx = 0

for i in A:
    while idx <= i:
        ans[idx] = i - idx
        idx += 1

for i in range(1, N+1):
    print(ans[i])