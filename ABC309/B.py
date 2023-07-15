import sys
input = sys.stdin.readline

N = int(input())
A = list(list(input().rstrip()) for _ in range(N))

new_A = [[-1] * N for _ in range(N)]

for y in range(N):
    for x in range(N):
        if x == 0 or y == 0 or x == N - 1 or y == N - 1:
            if x == 0 and y != N-1:
                new_A[y][x] = A[y+1][x]
            elif y == 0 and x != 0:
                new_A[y][x] = A[y][x-1]
            elif x == N-1 and y != 0:
                new_A[y][x] = A[y-1][x]
            elif y == N-1 and x != N-1:
                new_A[y][x] = A[y][x+1]
        else:
            new_A[y][x] = A[y][x]

for y in range(N):
    for x in range(N):
        print(new_A[y][x], end="")
    print()
