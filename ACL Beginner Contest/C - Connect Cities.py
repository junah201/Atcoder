import sys
sys.setrecursionlimit(10000000)

N, M = map(int, sys.stdin.readline().split())

graph = [[] for _ in range(N+10)]
visited = [False for _ in range(N+10)]

for _ in range(M):
    a, b = map(int, sys.stdin.readline().split())
    graph[a-1].append(b-1)
    graph[b-1].append(a-1)

def dfs(idx : int):
    visited[idx] = True
    for i in graph[idx]:
        if not visited[i]:
            dfs(i)

cnt = 0

for i in range(N):
    if not visited[i]:
        dfs(i)
        cnt += 1

print(cnt - 1)