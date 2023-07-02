import sys
from decimal import Decimal

input = sys.stdin.readline

N = int(input())
A = []
for i in range(N):
    a, b = map(int, input().split())
    rate = Decimal(a) / Decimal(a + b)
    A.append((rate, -(i + 1)))

A.sort(reverse=True)


for i in A:
    print(-i[1], end=" ")
