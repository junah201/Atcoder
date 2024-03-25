def getDigit(number):
    return len(f"{number:b}")


def intToBinary(curNumber, finalNumberDigit):
    return f"{curNumber:0={finalNumberDigit + (finalNumberDigit // 4) - (1 if not finalNumberDigit % 4 else 0)}_b}"


def intToBinary2(curNumber, finalNumberDigit):
    tmp = f"{curNumber:>0{finalNumberDigit}b}"
    return '_'.join([tmp[i:i+4] for i in range(0, len(tmp), 4)])


if __name__ == "__main__":
    finalNum = 2048
    digitOfFinalNum = getDigit(finalNum)

    for i in range(1, finalNum):
        print(intToBinary2(i, digitOfFinalNum))
