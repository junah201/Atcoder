Y, X, N = map(int, input().split())
graph = [
    [True] * (X + 2)
    for _ in range(Y + 2)
]

for _ in range(N):
    x, y = map(int, input().split())
    graph[y][x] = False


def find_max_rectangles(Y, X, graph):
    dp = [[[0, 0] for _ in range(X + 2)] for _ in range(Y + 2)]

    for y in range(1, Y + 1):
        for x in range(1, X + 1):
            if graph[y][x]:
                # Calculate the number of rectangles that can be formed using (y, x) as the bottom-right corner
                dp[y][x][0] = min(dp[y-1][x-1][0], dp[y-1]
                                  [x][0], dp[y][x-1][0]) + 1
                dp[y][x][1] = dp[y-1][x][1] + 1  # height of the rectangle

    max_rectangles = 0
    for y in range(1, Y + 1):
        for x in range(1, X + 1):
            if graph[y][x]:
                # Calculate the number of rectangles that can be formed using (y, x) as the top-left corner
                for size in range(1, dp[y][x][0] + 1):
                    max_rectangles = max(max_rectangles, size * dp[y][x][1])

    return max_rectangles


result = find_max_rectangles(Y, X, graph)
print(result)
