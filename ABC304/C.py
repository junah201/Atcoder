from collections import deque
N, D = map(int, input().split())
D = D * D

INF = 10 ** 18
is_virus = [False for _ in range(N)]
is_virus[0] = True

xy = []
dist = [
    [INF for _ in range(N)] for _ in range(N)
]

for i in range(N):
    x, y = map(int, input().split())
    xy.append([x, y])

for i in range(N):
    for j in range(i + 1, N):
        if i == j:
            continue

        dist[i][j] = dist[j][i] = (
            xy[i][0] - xy[j][0]) ** 2 + (xy[i][1] - xy[j][1]) ** 2

q = deque([0])

while q:
    now = q.popleft()

    for i in range(N):
        if dist[now][i] <= D and not is_virus[i]:
            is_virus[i] = True
            q.append(i)

for i in range(N):
    if is_virus[i]:
        print("Yes")
    else:
        print("No")
