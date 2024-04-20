import sys
input = sys.stdin.readline

N = input().strip()

contests = [
    f"ABC{i:03}" for i in range(1, 350)
    if i != 316
]

if N in contests:
    print("Yes")
else:
    print("No")
