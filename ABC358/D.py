import sys
input = sys.stdin.readline

N, M = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

A.sort()
B.sort()

A_idx = 0
B_idx = 0

total_price = 0


while A_idx < N and B_idx < M:
    if B[B_idx] > A[A_idx]:
        A_idx += 1
        continue

    total_price += A[A_idx]
    B_idx += 1
    A_idx += 1

if B_idx == M:
    print(total_price)
else:
    print("-1")
