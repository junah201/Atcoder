N = int(input())
A = []
for _ in range(N):
    A.append(input())

for i in range(N):
    for j in range(N):
        if i == j:
            continue
        tmp = A[i] + A[j]
        if tmp == tmp[::-1]:
            print("Yes")
            exit()

print("No")
