import sys
N, K = map(int, sys.stdin.readline().split())
S = list(sys.stdin.readline().rstrip())


cnt = 0
for i in range(N):
    if S[i] == 'o':
        if cnt < K:
            cnt += 1
        else:
            S[i] = 'x'

print(''.join(S))
