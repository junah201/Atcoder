import sys
input = sys.stdin.readline

S = list(input().rstrip())

for i in range(0, len(S) - 1):
    if S[i] <= S[i + 1]:
        print("No")
        exit()

print("Yes")
