N = int(input())

A = []

min_idx = 0

for i in range(N):
    name, age = input().split()
    A.append([int(age), name, i])

    if A[min_idx][0] > int(age):
        min_idx = i

for i in range(min_idx, min_idx + N):
    print(A[i % N][1])
