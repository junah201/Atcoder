X, Y, Z = map(int, input().split())
S = input()

INT_MAX = float("inf")

DP = [
    [
        INT_MAX for _ in range(len(S))
    ] for _ in range(2)
]

if S[0] == 'A':
    DP[0][0] = Y
    DP[1][0] = Z + X

elif S[0] == 'a':
    DP[0][0] = X
    DP[1][0] = Z + Y


for i in range(1, len(S)):
    if S[i] == 'A':
        DP[0][i] = min(DP[0][i], DP[0][i-1] + Y)
        DP[0][i] = min(DP[0][i], DP[1][i-1] + Z + Y)

        DP[1][i] = min(DP[1][i], DP[1][i-1] + X)
        DP[1][i] = min(DP[1][i], DP[0][i-1] + Z + X)

    elif S[i] == 'a':
        DP[0][i] = min(DP[0][i], DP[0][i-1] + X)
        DP[0][i] = min(DP[0][i], DP[1][i-1] + Z + X)

        DP[1][i] = min(DP[1][i], DP[1][i-1] + Y)
        DP[1][i] = min(DP[1][i], DP[0][i-1] + Z + Y)


print(min(DP[0][-1], DP[1][-1]))
