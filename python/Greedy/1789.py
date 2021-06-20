import sys

if __name__ == "__main__":
    S = int(sys.stdin.readline().rstrip())
    _sum=0
    N=0
    if(S==1):
        print(1)
    else:
        for i in range(1,S+1):
            if(_sum<=S):
                _sum+=i
            if(_sum>S):
                N=i
                break
        
        print(N-1)
