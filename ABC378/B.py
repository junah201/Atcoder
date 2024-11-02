import sys

input = sys.stdin.readline

max_day = 10 ** 9 + 1

N = int(input())
QR = [
    list(map(int, input().split()))
    for _ in range(N)
]

Q = int(input())
for _ in range(Q):
    t, d = map(int, input().split())
    q, r = QR[t - 1]

    if d % q == r:
        print(d)
        continue

    if d - d % q + r >= d:
        print(d - d % q + r)
    else:
        print(d - d % q + r + q)
