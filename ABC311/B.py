import sys

input = sys.stdin.readline

N, D = map(int, input().split())
can = [True] * D

for _ in range(N):
    tmp = list(input())
    for i in range(D):
        if tmp[i] == 'x':
            can[i] = False

ans = 0
cnt = 0

for i in can:
    if i:
        cnt += 1
    else:
        cnt = 0

    ans = max(ans, cnt)

print(ans)
