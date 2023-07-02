A = list(map(int, input().split()))

for i in range(1, 8):
    if A[i] < A[i-1]:
        print("No")
        exit()


for i in A:
    if i >= 100 and i <= 675:
        pass
    else:
        print("No")
        exit()

    if i % 25 != 0:
        print("No")
        exit()

print("Yes")
