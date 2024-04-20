# Python3 program to find
# minimum number of swaps
# required to sort an array

# Function returns the minimum
# number of swaps required to
# sort the array

swaps = []


def minSwaps(arr):
    global swaps
    n = len(arr)

    # Create two arrays and use
    # as pairs where first array
    # is element and second array
    # is position of first element
    arrpos = [*enumerate(arr)]

    # Sort the array by array element
    # values to get right position of
    # every element as the elements
    # of second array.
    arrpos.sort(key=lambda it: it[1])

    # To keep track of visited elements.
    # Initialize all elements as not
    # visited or false.
    vis = {k: False for k in range(n)}

    # Initialize result
    ans = 0
    for i in range(n):

        # already swapped or
        # already present at
        # correct position
        if vis[i] or arrpos[i][0] == i:
            continue

        # find number of nodes
        # in this cycle and
        # add it to ans

        cycle = []
        cycle_size = 0
        j = i

        while not vis[j]:
            prev = j
            # mark node as visited
            vis[j] = True
            # move to next node
            cycle.append(arrpos[j])
            j = arrpos[j][0]

            cycle_size += 1

        # update answer by adding
        # current cycle
        if cycle_size > 0:
            ans += (cycle_size - 1)
            swaps.append(cycle)

    # return answer
    return ans


# Driver Code
N = int(input())
A = list(map(int, input().split()))
print(minSwaps(A))

for s in swaps:
    for i in range(len(s) - 1):
        t1, t2 = s[i][0] + 1, s[i + 1][0] + 1
        print(min(t1, t2), max(t1, t2))

# This code is contributed
# by Dharan Aditya
