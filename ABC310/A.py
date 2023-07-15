N, P, Q = map(int, input().split())
D = list(map(int, input().split()))


ans = P

for i in range(N):
    ans = min(ans, D[i] + Q)

print(ans)
