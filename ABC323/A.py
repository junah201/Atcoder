import sys
from collections import defaultdict, deque
input = sys.stdin.readline

S = input().rstrip()


if "1" in S[1::2]:
    print("No")
else:
    print("Yes")