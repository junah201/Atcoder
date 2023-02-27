A = input()

for idx, i in enumerate(A):
    if i == i.upper():
        print(idx+1)
        exit()
