A, B = map(int, input().split())

start = 1
count = 0

while start < B:
    start += A - 1
    count += 1

print(count)
