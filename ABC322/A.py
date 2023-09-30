import sys
input = sys.stdin.readline

N = int(input())
S = input()

idx =  S.find("ABC")
if idx == -1:
    print(idx)
else:
    print(idx + 1)