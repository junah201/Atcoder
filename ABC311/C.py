N = int(input())
A = [i - 1 for i in list(map(int, input().split()))]
visited = [False] * N
prev = [-1] * N

is_all_cycle = False
is_cycle = [False] * N
ans = []


def dfs(v, idx):
    global is_all_cycle
    if visited[v] == idx:
        is_cycle[v] = True
        is_all_cycle = True
        return

    if visited[v]:
        return

    visited[v] = idx
    prev[A[v]] = v
    dfs(A[v], idx)

    if not is_all_cycle:
        return

    if is_cycle[v]:
        now = v
        while True:
            ans.append(now)
            now = prev[now]

            if now == v:
                break

        print(len(ans))
        print(*[i + 1 for i in ans[::-1]])
        exit()


for i in range(N):
    if visited[i]:
        continue

    dfs(i, i+1)
