import sys
input = sys.stdin.readline

S = input().strip()
T = list(input().strip())

S = list(S.upper())

if T[-1] == "X":
    T = T[:-1]


for s in S:
    if s == T[0]:
        T.pop(0)
        if len(T) == 0:
            print("Yes")
            exit()

print("No")
