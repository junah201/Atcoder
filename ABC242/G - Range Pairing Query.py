import sys
sys.setrecursionlimit(10000000)

'''
map(int, sys.stdin.readline().split())
int(sys.stdin.readline())
'''


N = int(sys.stdin.readline())
A = list(map(int, sys.stdin.readline().split()))
Q = int(sys.stdin.readline())

sum_Arr = [[0 for _ in range(N+1)]]

for i in range(N):
    sum_Arr.append(list(sum_Arr[-1]))
    sum_Arr[i+1][A[i]] += 1


for _ in range(Q):
    L, R = map(int, sys.stdin.readline().split())
    ans = 0
    for i in range(1, N+1, 1):
        ans += (sum_Arr[R][i] - sum_Arr[L-1][i]) // 2

    print(ans)