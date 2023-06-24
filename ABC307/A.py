N = int(input())
A = list(map(int, input().split()))

idx = 0
for _ in range(N):
    ans = 0
    for i in range(7):
        ans += A[idx]
        idx += 1
    print(ans, end=" ")
