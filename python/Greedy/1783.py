import sys


if __name__ == "__main__":
    N, M = map(int, sys.stdin.readline().rstrip().split())
    if N == 1:
        scount = 1
    elif N == 2:
        scount = min(4, (M-1)//2 + 1)
    elif M < 7:
        scount = min(4, M)
    else:
        scount = (2 + (M-5)) + 1
    print(scount)
