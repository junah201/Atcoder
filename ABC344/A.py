import sys
input = sys.stdin.readline

n = input().strip()

check = False
for i in list(n):
    if i == '|':
        check = not check
        continue

    if check:
        continue

    print(i, end='')
