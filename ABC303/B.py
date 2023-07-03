N, M = map(int, input().split())
inp = []
A = [
    [0 for _ in range(N)]
    for _ in range(N)
]

for _ in range(M):
    inp.append(list(map(int, input().split())))

for i in range(M):
    for j in range(N):
        if j != 0:
            A[inp[i][j] - 1][inp[i][j - 1] - 1] = 1
        if j != N - 1:
            A[inp[i][j] - 1][inp[i][j + 1] - 1] = 1

for i in range(N):
    for j in range(N):
        if i == j:
            A[i][j] = 1

ans = 0
for i in range(N):
    for j in range(N):
        if A[i][j] == 0:
            ans += 1

print(ans // 2)
