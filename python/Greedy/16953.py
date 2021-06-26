import sys


if __name__ == "__main__":
    A, B = map(int, sys.stdin.readline().rstrip().split())
    answer = 0
    find = False
    while(A <= B):
        if(A == B):
            find = True
            break
        else:
            if(B % 10 == 1):
                B -= 1
                B //= 10
                answer += 1
            elif(B % 2 == 0):
                B //= 2
                answer += 1
            else:
                break
    print(answer+1) if find == True else print(-1)
