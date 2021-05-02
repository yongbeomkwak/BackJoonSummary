import sys

if __name__ == "__main__":
   x=int(sys.stdin.readline())
   for y in range(0,x):
        num=sys.stdin.readline().rstrip().split(" ")
        a=int(num[0])
        b=int(num[1])
        print(a+b)



    