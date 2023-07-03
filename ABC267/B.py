graph = [
    [],
    [2, 3, 5, 8, 9],  # 1
    [4, 8, 5, 1],
    [1, 5, 9, 6],
    [7, 8, 2],  # 4
    [8, 2, 1, 3, 9],
    [3, 9, 10],
    [4],
    [4, 2, 5, 1],
    [5, 1, 3, 6],
    [6]
]

check = [False for i in range(11)]
ans = 0
S = ["0"] + list(input())

if S[1] == "1":
    print("No")
    exit()


def dfs(idx):
    global check
    global graph
    global S
    if check[idx] or S[idx] == "0":
        return
    check[idx] = True

    for next in graph[idx]:
        dfs(next)


for idx in range(1, 11):
    if check[idx] == False and S[idx] == "1":
        dfs(idx)
        ans += 1

if ans == 1:
    print("No")
elif ans > 1:
    print("Yes")
else:
    print("Yes")
