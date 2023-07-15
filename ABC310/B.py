import sys
input = sys.stdin.readline

N, M = map(int, input().split())

P = []
C = []
F = []

for i in range(N):
    tmp = list(map(int, input().split()))
    tP, tC = tmp[0], tmp[1]
    tF = tmp[2:]

    P.append(tP)
    C.append(tC)
    F.append(set(tF))


for i in range(N):
    for j in range(N):
        if i == j:
            continue

        if P[i] < P[j]:
            continue

        if not F[j].issuperset(F[i]):
            continue

        if P[i] <= P[j] and len(F[i]) == len(F[j]):
            continue

        print("Yes")
        exit()


print("No")
