import sys
input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))

if N == 1:
    print(0)
    exit()

ans = max(A[1:]) - A[0]
if ans < 0:
    print(0)
else:
    print(ans + 1)
