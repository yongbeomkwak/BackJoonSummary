import sys


def solve(a):
    if(a <= 99):
        return a
    else:
        count = 99
        for i in range(a, 99, -1):
            th = i//1000
            h = (i % 1000)//100
            t = (i % 100)//10
            o = (i % 10)
            if(th == 0):
                if((h-t) == (t-o)):
                    count += 1
            else:
                continue
        return count


if __name__ == "__main__":
    num = int(sys.stdin.readline())
    print(solve(num))
