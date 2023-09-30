from copy import deepcopy

def print_list(T : list):
    for y in range(len(T)):
        for x in range(len(T[y])):
            print(f"#" if T[y][x] else ".", end='')
        print()

def print_list(T : list):
    for y in range(len(T)):
        for x in range(len(T[y])):
            print(T[y][x], end=' ')
        print()


tmp_sum = 0

A = []
for _ in range(4):
    tmp = list(input().rstrip())
    tmp = [True if i == '#' else False for i in tmp]
    tmp_sum += sum(tmp)
    A.append(tmp)

B = []
for _ in range(4):
    tmp = list(input().rstrip())
    tmp = [True if i == '#' else False for i in tmp]
    tmp_sum += sum(tmp)
    B.append(tmp)

C = []
for _ in range(4):
    tmp = list(input().rstrip())
    tmp = [True if i == '#' else False for i in tmp]
    tmp_sum += sum(tmp)
    C.append(tmp)

if tmp_sum != 4 * 4:
    print("No")
    exit()


def get_min_list(T: list) -> list:
    min_list = []
    # 세로 줄

    y_start = 0
    y_end = 3
    x_start = 0
    x_end = 3

    for y in range(4):
        if any(T[y]):
            y_start = y
            break

    for y in range(3, -1, -1):
        if any(T[y]):
            y_end = y
            break

    for x in range(4):
        if any([T[y][x] for y in range(4)]):
            x_start = x
            break

    for x in range(3, -1, -1):
        if any([T[y][x] for y in range(4)]):
            x_end = x
            break

    for y in range(y_start, y_end + 1):
        tmp = []
        for x in range(x_start, x_end + 1):
            tmp.append(T[y][x])
        min_list.append(tmp) 

    return min_list

def rotate(T: list) -> list:
    tmp = deepcopy(T)
    len_y = len(T)
    len_x = len(T[0])
    ret = [[False for _ in range(len_y)] for _ in range(len_x)]

    for y in range(len_y):
        for x in range(len_x):
            ret[x][len_y - 1 - y] = tmp[y][x]

    return ret

min_A = get_min_list(A)
r_min_A = rotate(min_A)
r_r_min_A = rotate(r_min_A)
r_r_r_min_A = rotate(r_r_min_A)

all_A = [min_A, r_min_A, r_r_min_A, r_r_r_min_A]

min_B = get_min_list(B)
r_min_B = rotate(min_B)
r_r_min_B = rotate(r_min_B)
r_r_r_min_B = rotate(r_r_min_B)

all_B = [min_B, r_min_B, r_r_min_B, r_r_r_min_B]

min_C = get_min_list(C)
r_min_C = rotate(min_C)
r_r_min_C = rotate(r_min_C)
r_r_r_min_C = rotate(r_r_min_C)

all_C = [min_C, r_min_C, r_r_min_C, r_r_r_min_C]

def just_check(A: list, B: list, C: list) -> bool:
    T = [[0 for _ in range(4)] for _ in range(4)]
    for y in range(len(A)):
        for x in range(len(A[0])):
            T[y][x] = A[y][x]
    for y in range(len(B)):
        for x in range(len(B[0])):
            if T[y][x] and B[y][x]:
                continue
            T[y][x] = B[y][x]
    for y in range(len(C)):
        for x in range(len(C[0])):
            if T[y][x] and C[y][x]:
                continue
            T[y][x] = C[y][x]   

    return all([all(T[y]) for y in range(4)])

def check(A: list, B: list, C: list) -> bool:
    if just_check(A, B, C):
        return True
    
    for a_start_x in range(4 - len(A[0]) + 1):
        for a_start_y in range(4 - len(A) + 1):
            for b_start_x in range(4 - len(B[0]) + 1):
                for b_start_y in range(4 - len(B) + 1):
                    for c_start_x in range(4 - len(C[0]) + 1):
                        for c_start_y in range(4 - len(C ) + 1):
                            T = [[0 for _ in range(4)] for _ in range(4)]
                            flag = False
                            for y in range(len(A)):
                                for x in range(len(A[0])):
                                    T[a_start_y + y][a_start_x + x] = 1 if A[y][x] else 0 

                            for y in range(len(B)):
                                for x in range(len(B[0])):
                                    if T[b_start_y + y][b_start_x + x] and B[y][x]:
                                        flag = True
                                        break
                                    T[b_start_y + y][b_start_x + x] = 2 if B[y][x] else T[b_start_y + y][b_start_x + x] 

                            if flag:
                                continue

                            for y in range(len(C)):
                                for x in range(len(C[0])):
                                    if T[c_start_y + y][c_start_x + x] and C[y][x]:
                                        flag = True
                                        break
                                    T[c_start_y + y][c_start_x + x] = 3 if C[y][x] else T[c_start_y + y][c_start_x + x] 

                            if flag:
                                continue
                        
                            if all([all(T[y]) for y in range(4)]):
                                return True



for A in all_A:
    for B in all_B:
        for C in all_C:
            if check(A, B, C):
                print("Yes")
                exit()

print("No")