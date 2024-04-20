import sys
input = sys.stdin.readline

N, Q = map(int, input().split())
T = list(map(int, input().split()))


S = set([
    i for i in range(1, N+1)
])

for i in T:
    if i in S:
        S.remove(i)
    else:
        S.add(i)

print(len(S))
