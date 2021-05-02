import sys

if __name__ == "__main__":
   x=int(sys.stdin.readline())
   for k in range(1,x+1):
    in_list=sys.stdin.readline().split(" ")
    a=int(in_list[0])
    b=int(in_list[1])
    print("Case #{0}: {1}".format(k,a+b))




    