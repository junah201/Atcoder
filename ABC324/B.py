import sys
from collections import defaultdict, deque
input = sys.stdin.readline

N = int(input())
x = 0
y = 0

while N % 2 == 0:
    N //= 2

while N % 3 == 0:
    N //= 3

if N == 1:
    print("Yes")
else:
    print("No")