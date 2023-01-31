import itertools

N = int(input())
P = list(map(str, input().split()))
A = list(itertools.permutations(P, N))
P = " ".join(P)
B = [" ".join(list(i)) for i in A]
B = [i for i in B if i < P]
print(max(B))
