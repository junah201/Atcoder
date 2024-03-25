import sys
input = sys.stdin.readline

T = input().strip()
N = int(input().strip())

Bags = []

for i in range(N):
    A = list(input().split())
    A = A[1:]
    Bags.append(A)

DP = [float('inf')] * (len(T) + 1)
DP[0] = 0

COPY_DP = DP[:]

K = {}

for i in range(len(T)):
    for j in range(1, 20):
        if i + j > len(T):
            continue
        if T[i:i + j] in K:
            K[T[i:i + j]].append(i)
        else:
            K[T[i:i + j]] = [i]

# for key, value in K.items():
#     print(key, value)

for bag in Bags:
    # print(bag)
    for s in bag:
        # print(s, K.get(s, []))
        for j in K.get(s, []):
            if COPY_DP[j] == float('inf'):
                continue
            COPY_DP[j + len(s)] = min(DP[j + len(s)], DP[j] + 1)

    DP = COPY_DP[:]
    # print(DP)

# print(DP[len(T)])

if DP[len(T)] >= float('inf'):
    print(-1)
else:
    print(DP[len(T)])
