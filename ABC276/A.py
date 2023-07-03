S = input()
ans = -1

for idx, i in enumerate(list(S)):
    if i == 'a':
        ans = idx + 1

print(ans)
