import sys


if __name__ == "__main__":
    N,L= map(int,sys.stdin.readline().rstrip().split())
    leak=list(map(int,sys.stdin.readline().rstrip().split()))
    answer=1
    leak.sort()
    left=leak[0]
    for i in range(1,N):
        right=leak[i]
        if(right-left>L-1):
            left=right
            answer+=1
    print(answer)

 
  
