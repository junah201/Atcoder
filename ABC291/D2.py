import sys
from collections import defaultdict

N = int(input())

K = defaultdict(list)

D = list()
DD = list()

ans = 0

for _ in range(N):
    A, B = map(int, sys.stdin.readline().split())


"""
x x x
o x x
x o x

x o o

o o o
o o x


x x o
o x o
"""
