import sys


if __name__ == "__main__":
    T = int(sys.stdin.readline().rstrip())
    A = 0
    B = 0
    C = 0
    if(T % 10 != 0):
        print(-1)
    else:
        while(T != 0):
            if(T >= 300):
                A = T//300
                T = T % 300
            elif(T >= 60):
                B = T//60
                T = T % 60
            else:
                C = T//10
                T = T % 10
        print(A, B, C)
