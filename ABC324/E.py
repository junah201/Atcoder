import sys
input = sys.stdin.readline

N, T= map(str, input().split())
N = int(N)
len_T = len(T)

S = [
    input().rstrip()
    for _ in range(N)
]

front = [0] * N
back = [len_T] * N
c = [0] * 500001

for i in range(N):
    idx = 0
    for j in S[i]:
        if j == T[idx]:
            idx += 1
            if idx == len_T:
                break
    
    front[i] = idx

    if idx == len_T:
        back[i] = -1
        c[back[i] + 1] += 1
        continue

    idx = len_T - 1
    for j in S[i][::-1]:
        if j == T[idx]:
            idx -= 1
            if idx == -1:
                break
    
    back[i] = idx
    c[back[i] + 1] += 1

ans = 0

for i in range(N):
    for j in range(front[i] + 1):
        ans += c[j]

print(ans)
