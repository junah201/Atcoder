import sys
input = sys.stdin.readline

INF = 99999999999999999

N, X= map(int, input().split())
A = list(map(int, input().split()))

A = sorted(A)

S = sum(A)

for i in range(0, 101):
    mn = A[0]
    mx = A[-1]

    if i < mn:
        mn = i
    if i > mx:
        mx = i


    if S + i - mn - mx >= X:
        print(i)
        exit()

print(-1)
