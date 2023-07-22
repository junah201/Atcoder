N = int(input())
A = list(input())

a, b, c = False, False, False

for i in range(N):
    if A[i] == 'A':
        a = True
    elif A[i] == 'B':
        b = True
    elif A[i] == 'C':
        c = True

    if a and b and c:
        print(i + 1)
        break
