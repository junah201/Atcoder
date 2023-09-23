import sys
from typing import List
input = sys.stdin.readline

N = int(input())
S = list(map(int, list(input().rstrip())))


def F(S: List[int]):
    new_S = []
    for i in range(len(S) - 1):
        if S[i] != 1 and S[i + 1] != 1:
            print(-1)
            exit()
        new_S.extend([S[i]] * S[i + 1])

    return new_S


cnt = 0

while True:
    cnt += 1
    cnt %= 998244353
    S = F(S)
    print(S)
    if len(S) == 1:
        print(cnt)
        exit()
