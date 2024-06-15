import sys
input = sys.stdin.readline

N, M = map(int, input().split())

ideal_ans = 0
for i in range(M):
    ideal_ans |= 1 << i

idx = [
    [] for _ in range(M)
]

S = [
    input().strip() for _ in range(N)
]

for i, s in enumerate(S):
    tmp = 0
    for j in range(M):
        if s[j] == 'o':
            # tmp의 i번째 비트를 활성화
            tmp |= 1 << j
            idx[j].append(i)
    S[i] = tmp


# print(S)

# for i in idx:
#     print(i)

answer = 999999


def dfs(i: int, now: int, cnt: int, cnt_bit: int):
    global answer

    if now == ideal_ans:
        answer = min(answer, cnt)
        return

    if i == M:
        return

    if cnt >= answer:
        return

    # i번째 비트가 활성화되어 있을 경우
    if now & 1 << i:
        dfs(i+1, now, cnt, cnt_bit)

    for j in idx[i]:
        dfs(
            i+1, now | S[j],
            cnt+1,
            cnt_bit | 1 << j
        )


dfs(0, 0, 0, 0)

print(answer)
