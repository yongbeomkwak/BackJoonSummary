import sys
sys.setrecursionlimit(2500)
N=0
M=0
arr=[0 for i in range(10)]
used=[False for i in range(10)]
def back(a:int,b:int):
    if(b==M):
        for i in range(M):
            print(arr[i],end=" ")
        print()
    else:
        for i in range(a,N+1):
            if(used[i]==False):
                used[i]=True
                arr[b]=i
                back(i+1,b+1)
                used[i]=False
            


if __name__ == "__main__":
    N,M=map(int,input().split(" "))

    back(1,0)
