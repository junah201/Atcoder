import sys
input = sys.stdin.readline
N = int(input())
A = []

for _ in range(N):
    tmp = input().rstrip()

    A.append(min(tmp, tmp[::-1]))

NA = set(A)

print(len(NA))
