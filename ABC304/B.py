N = int(input())


if N < 10 ** 3:
    print(N)
elif N < 10 ** 4:
    print(N - N % 10)
elif N < 10 ** 5:
    print(N - N % 100)
elif N < 10 ** 6:
    print(N - N % 1000)
elif N < 10 ** 7:
    print(N - N % 10000)
elif N < 10 ** 8:
    print(N - N % 100000)
elif N < 10 ** 9:
    print(N - N % 1000000)
else:
    print("ERROR")
