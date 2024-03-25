import sys
from collections import defaultdict, deque
input = sys.stdin.readline

N = int(input())

K = []
time = [0] * 24

for i in range(N):
    w, x = map(int, input().split())
    for i in range(9, 18):
        t = (i + x) % 24
        time[t] += w

print(max(time))
