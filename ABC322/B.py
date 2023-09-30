import sys
input = sys.stdin.readline

N, M = map(int, input().split())
S = input().rstrip()
T = input().rstrip()

is_prefix = False
is_suffix = False

if T.startswith(S):
    is_prefix = True

if T.endswith(S):
    is_suffix = True

if is_prefix and is_suffix:
    print(0)
elif is_prefix:
    print(1)
elif is_suffix:
    print(2)
else:
    print(3)