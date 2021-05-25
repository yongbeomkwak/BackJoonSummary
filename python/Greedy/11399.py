import sys
sys.setrecursionlimit(2500)


if __name__ == "__main__":

    N = int(sys.stdin.readline())
    time=list(map(int,input().split()))
    time.sort()
    
    count=[0] * N
    count[0]=time[0]
    for i in range(1,N):
        count[i]=count[i-1]+time[i]

    print(sum(count))    

    