import sys
N, K = map(int, sys.stdin.readline().split())

S = list(sys.stdin.readline().rstrip())

DP = [0 for _ in range(K + 1)]
