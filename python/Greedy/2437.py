import sys


if __name__ == "__main__":
    N= sys.stdin.readline().rstrip()
    arr=list(map(int,sys.stdin.readline().rstrip().split()))
    arr.sort()
    S=0
    
    for val in arr:
        if(S+1<val):
            break
        S+=val
    print(S+1)
  
