import sys
from collections import defaultdict, deque
input = sys.stdin.readline
import math

N = int(input())

S = list(map(int, list(input().rstrip())))
count_zero = S.count(0)
T = [0] * 10

for i in S:
    T[i] += 1

m = [0,9, 99, 999, 9999, 99999, 999999 , 9999999, 99999999, 999999999, 9999999999, 99999999999, 999999999999, 9999999999999]

max_S = m[N]

def check(제: str):
    K = [0] * 10

    for i in 제:
        K[int(i)] += 1

    for i in range(1,10):
        if K[i] != T[i]:
            return False

    return True

ans = 0


def get():
    max_sorted_S = sorted(S, reverse=True)
    min_sorted_S = max_sorted_S[::-1]

    max_S = int("".join(map(str, max_sorted_S)))
    min_S = int("".join(map(str, min_sorted_S)))

    for i in range(math.floor(math.sqrt(min_S)), 9999999999999):
        if i ** 2 > max_S:
            break
        yield i ** 2

for i in get():
    if check(str(i)):
        ans += 1

print(ans)