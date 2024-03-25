import sys
input = sys.stdin.readline

possible_values = set()

N = int(input().strip())
A = list(map(int, input().split()))
M = int(input().strip())
B = list(map(int, input().split()))
L = int(input().strip())
C = list(map(int, input().split()))
Q = int(input().strip())
X = list(map(int, input().split()))

max_value = max(X)

for a in A:
    if a > max_value:
        continue
    for b in B:
        if a + b > max_value:
            continue
        for c in C:
            if a + b + c > max_value:
                continue
            possible_values.add(a + b + c)


for x in X:
    if x in possible_values:
        print('Yes')
    else:
        print('No')
