import sys
from collections import defaultdict, deque
input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))

if len(set(A)) == 1:
    print("Yes")
else:
    print("No")