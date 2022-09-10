N = list(input().split())

tmp = []

for i in N:
    if i in tmp:
        continue
    tmp.append(i)

print(len(tmp))
