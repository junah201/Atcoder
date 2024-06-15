from itertools import product
import sys
input = sys.stdin.readline

K = int(input())
C = list(map(int, input().split()))
total = sum(C)

ans = 0

# 팩토리얼 계산
DP = [0] * (total + 1)
DP[0] = 1

DP[1] = sum([
    1 for i in C if i
])
print(1,  DP[1])
for i in range(2, min(K, sum(C))+1):
    DP[i] = DP[1] ** i
    print(i, DP[i])

exit()


def C_to_string():
    s = ""
    for i in range(len(C)):
        s += chr(ord('a') + i) * C[i]
    return s


def dfs():
    global ans
    global total
    # print(ans)

    if total == 0:
        return

    if total > K:
        for i in range(len(C)):
            if C[i]:
                C[i] -= 1
                total -= 1
                dfs()
                C[i] += 1
                total += 1
        return

    tmp = 1
    for i in range(len(C)):
        tmp *= P[C[i]]

    print(C_to_string())
    print(tmp, P[total] // tmp)

    ans += P[total] // tmp

    for i in range(len(C)):
        if C[i]:
            C[i] -= 1
            total -= 1
            dfs()
            C[i] += 1
            total += 1


"""
1, 3 -> 3
a
b
c

2, 3 -> 12
aa
ab
ac
ba
bc
ca
cb

"""

dfs()
print(ans)
