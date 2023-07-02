import sys
input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))
S = list(input().strip())

M = []
E = []
X = []


for i in range(N):
    if S[i] == "M":
        M.append((i, A[i]))
    elif S[i] == "E":
        E.append((i, A[i]))
    else:
        X.append((i, A[i]))
