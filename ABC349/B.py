import sys
input = sys.stdin.readline

S = input().strip()

A = [
    0 for _ in range(30)
]

for s in S:
    A[ord(s) - ord('a')] += 1

for i in range(1, 101):
    cnt = 0
    for j in A:
        if i == j:
            cnt += 1
    if cnt == 0 or cnt == 2:
        continue
    else:
        print('No')
        exit()

print('Yes')
