import sys
input = sys.stdin.readline

A, B = map(int, input().split())


if B not in [4, 7] and B - 1 == A:
    print("Yes")
    exit()
elif B + 3 == A:
    print("Yes")
    exit()

print("No")
