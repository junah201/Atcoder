import sys
from collections import defaultdict, deque
input = sys.stdin.readline

N = int(input())
A = [
    list(input().rstrip()) for _ in range(N)
]

K = []

for idx, value in enumerate(A):
    K.append((value.count("o"), -(idx + 1)))

K.sort(reverse=True)

print(" ".join([str(-i[1]) for i in K]))