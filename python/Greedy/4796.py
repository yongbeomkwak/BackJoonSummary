import sys


def solve(L: int, P: int, V: int, i: int):
    K = V % P if L > V % P else L
    result = (V//P) * L + K
    print("Case {0}: {1}".format(i, result))


if __name__ == "__main__":
    i = 1
    while(True):
        L, P, V = map(int, sys.stdin.readline().rstrip().split())
        if(L+P+V == 0):
            break
        solve(L, P, V, i)
        i += 1
