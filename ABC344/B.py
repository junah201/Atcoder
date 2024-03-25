import sys
input = sys.stdin.readline

lines = sys.stdin.readlines()

for line in lines[::-1]:
    print(line.strip())
