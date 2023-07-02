N, M = map(int, input().split())
C = list(input().split())
D = list(input().split())
P = list(map(int, input().split()))


price = {}

for i in range(M):
    price[D[i]] = P[i+1]


ans = 0
for i in C:
    ans += price.get(i, int(P[0]))

print(ans)
