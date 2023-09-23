import sys
input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))

a_sum = sum(A)
a_min = a_sum // N
a_max = a_sum // N + 1
if a_sum % N == 0:
    a_max -= 1

if a_max == a_min:
    print(0)
    exit()

A = sorted(A)

low_ans_cnt = N - a_sum % N
high_ans_cnt = a_sum % N
low_cnt = 0
high_cnt = 0


def target(idx: int):
    if idx < low_ans_cnt:
        return a_min
    else:
        return a_max


low = 0
high = N - 1

ans = 0

while low < high:
    if A[low] == target(low):
        low += 1
        continue

    if A[high] == target(high):
        high -= 1
        continue

    # print("low", A[low], "high", A[high], "ans", ans)

    tmp1 = abs(target(low) - A[low])
    tmp2 = abs(A[high] - target(high))

    # print("tmp1", tmp1, "tmp2", tmp2)

    tmp = min(tmp1, tmp2)

    A[low] += tmp
    A[high] -= tmp
    ans += tmp

# print(A)

print(ans)
