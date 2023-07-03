N = int(input())
S = input()

is_visited = set()

x = 0
y = 0

is_visited.add((x, y))

for i in S:
    if i == 'L':
        x -= 1
    elif i == 'R':
        x += 1
    elif i == 'U':
        y += 1
    elif i == 'D':
        y -= 1

    if (x, y) in is_visited:
        print('Yes')
        exit()

    is_visited.add((x, y))

print('No')
