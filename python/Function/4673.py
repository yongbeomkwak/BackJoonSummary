import sys


def solve(a):

    for i in range(a, 0, -1):
        result = 0
        if(i < 10):
            result = i+i
            if(result < a):
                return False
            elif(result == a):
                return True
        elif(i >= 10 and i < 100):
            result = i+(i//10)+(i % 10)
            if(result == a):
                return True
        elif(i >= 100 and i < 1000):
            result = i+(i//100)+((i % 100)//10)+((i % 10))
            if(result == a):
                return True
        elif(i >= 1000 and i < 10000):
            result = i+(i//1000)+((i % 1000)//100)+((i % 100)//10)++((i % 10))
            if(result == a):
                return True


if __name__ == "__main__":
    for i in range(1, 10001):
        if(solve(i)):
            continue
        else:
            print(i)
