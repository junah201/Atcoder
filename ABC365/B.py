import sys
from collections import defaultdict, deque
input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))

A = [
    (a, i + 1)
    for i, a in enumerate(A)
]

A.sort(reverse=True)

print(A[1][1])
