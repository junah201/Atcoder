import sys
from collections import defaultdict, deque
input = sys.stdin.readline


Rock = 0
Scissors = 1
Paper = 2


def get_game_result(a: int, b: int):
    # a가 이기면 win, 비기면 draw, 지면 lose
    if (a == Rock and b == Scissors) or (a == Scissors and b == Paper) or (a == Paper and b == Rock):
        return "win"
    if a == b:
        return "draw"
    return "lose"


def str_to_int(s: str) -> int:
    if s == "R":
        return Rock
    if s == "S":
        return Scissors
    if s == "P":
        return Paper
    return -1


N = int(input())
S = input().strip()
# print(list(S))
S = ["X"] + [
    str_to_int(s)
    for s in S
]

# print(S[1:])

DP = [
    [0] * 3
    for _ in range(N + 1)
]

ans = 1

for i in range(1, N + 1):
    for move in [Rock, Scissors, Paper]:
        result = get_game_result(move, S[i])

        if result == "lose":
            DP[i][move] = 0
        elif result == "win":
            DP[i][move] = max([
                DP[i - 1][before_move]
                for before_move in [Rock, Scissors, Paper]
                if before_move != move
            ]) + 1
        else:
            DP[i][move] = max([
                DP[i - 1][before_move]
                for before_move in [Rock, Scissors, Paper]
                if before_move != move
            ])

    ans = max([
        ans,
        max(DP[i])
    ])

# print(["R", "S", "P"])
# for idx, i in enumerate(DP[1:]):
#     print(idx + 1, i)

print(ans)
