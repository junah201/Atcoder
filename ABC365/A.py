import sys
from collections import defaultdict, deque
input = sys.stdin.readline

N = int(input())

if N % 4 != 0:
    print("365")
    exit()

if N % 4 == 0 and N % 100 != 0:
    print("366")
    exit()

if N % 100 == 0 and N % 400 != 0:
    print("365")
    exit()

print("366")
