import sys
input = sys.stdin.readline

N, A = map(int, input().split())
T = [-1] + list(map(int, input().split()))

ans = [0] + [i * A for i in range(N)]

for i in range(1, N+1):
    # print(ans[i-1], ans[i], T[i])
    ans[i] = max(ans[i-1], T[i]) + A

for i in ans[1:]:
    print(i)
