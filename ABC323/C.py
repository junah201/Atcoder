import sys
from collections import defaultdict, deque
input = sys.stdin.readline

N, M = map(int, input().split())
A = list(map(int, input().split()))
sorted_A = sorted([
    (value, idx) for idx, value in enumerate(A)
], reverse=True)
player = [
    list(input().rstrip()) for _ in range(N)
]
score = [
    0 for _ in range(N)
]
max_score = 0

for idx, value in enumerate(player):
    tmp = idx + 1
    for i in range(M):
        if value[i] == "o":
            tmp += A[i]
    max_score = max(max_score, tmp)
    score[idx] = tmp


for idx, value in enumerate(score):
    if value >= max_score:
        print(0)
        continue

    cnt = 0

    for s, i in sorted_A:
        if player[idx][i] == 'o':
            continue
    
        value += s
        cnt += 1

        if value >= max_score:
            break

    print(cnt)
