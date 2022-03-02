import sys
sys.setrecursionlimit(10000000)

N = int(sys.stdin.readline())

graph = [[] for _ in range(N+1)]
visited = [False for _ in range(N+1)]

for _ in range(N-1):
    a, b = map(int, sys.stdin.readline().split())
    graph[a].append(b)
    graph[b].append(a)

for i in range(1,N+1):
    graph[i].sort()

def dfs(idx : int):
    visited[idx] = True
    print(idx, end = " ")
    for i in range(len(graph[idx])):
        if visited[graph[idx][i]]:
            continue
        dfs(graph[idx][i])
        print(idx, end = " ")

dfs(1)