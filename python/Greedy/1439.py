import sys


if __name__ == "__main__":
    N = sys.stdin.readline().rstrip()
    zero = 0
    one = 0
    if(N[0] == '0'):
        zero += 1
    else:
        one += 1

    for i in range(1, len(N)):
        if(N[i] != N[i-1]):
            if(N[i] == '0'):
                zero += 1
            else:
                one += 1

    print(min(zero, one))
