import sys

N = int(sys.stdin.readline())
user = list(map(int, sys.stdin.readline().split()))
ans = 0


def cul():
    global user
    result = 0
    for i in range(N):
        if user[i] == ((i - 1) % N):
            result += 1
        elif user[i] == i:
            result += 1
        elif user[i] == ((i + 1) % N):
            result += 1
    return result


for _ in range(N):
    ans = max(ans, cul())
    if ans == N:
        break
    user.append(user.pop(0))

print(ans)
