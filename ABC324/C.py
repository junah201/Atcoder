import sys
from collections import defaultdict, deque
input = sys.stdin.readline

N, T = map(str, input().split())
N = int(N)


ans = []

def check_equal(S: str):
    if S == T:
        return True
    else:
        return False

def check_insert(S: str):
    if len(S) + 1 != len(T):
        return False

    longer = T
    shorter = S

    for i in range(len(shorter)):
        if shorter[i] != longer[i]:
            return shorter[i:] == longer[i + 1:]

    return True


def check_delete(S: str):
    if len(S) - 1 != len(T):
        return False

    longer = S
    shorter = T

    for i in range(len(shorter)):
        if shorter[i] != longer[i]:
            return shorter[i:] == longer[i + 1:]

    return True

def check_change(S: str):
    if len(S) != len(T):
        return False

    for i in range(len(S)):
        if S[i] != T[i]:
            return S[i+1:] == T[i + 1:]

    return True
    

for i in range(N):
    S = input().rstrip()

    # print(i + 1, f"|{T}|")
    # print(check_insert(S))

    if check_equal(S):
        ans.append(i+1)
    elif check_insert(S):
        ans.append(i+1)
    elif check_delete(S):
        ans.append(i+1)
    elif check_change(S):
        ans.append(i+1)


print(len(ans))
print(*ans, sep=" ")

