N = int(input())
graph = [i - 1 for i in list(map(int, input().split()))]

visited = [False] * N
stack = []
is_cycle = False
start_cycle = -1


def dfs(node, idx):
    global is_cycle, start_cycle
    visited[node] = idx

    next = graph[node]

    if visited[next] == idx:
        stack.append(node)
        start_cycle = next
        is_cycle = True
        return

    if not visited[next]:
        dfs(next, idx)

    if is_cycle:
        stack.append(node)
        if node == start_cycle:
            print(len(stack))
            print(*[i + 1 for i in stack[::-1]])
            exit()

    return False


for i in range(N):
    if not visited[i]:
        dfs(i, i+1)
