import sys
input = sys.stdin.readline

N, M = map(int, input().split())
H = list(map(int, input().split()))

cnt = 0

for i in H:
    if i <= M:
        M -= i
        cnt += 1
    else:
        break

print(cnt)
