import sys


if __name__ == "__main__":
    N = int(sys.stdin.readline().rstrip())
    _str=(sys.stdin.readline().rstrip())
    ans=0
    roop=0
    if(N<=2):
        ans=N;
        print(ans)
    else:
        ans=1
        while (roop<len(_str)):
            if(ans<N):
                if(_str[roop]=="S"):
                    roop+=1
                    ans+=1
                else:
                    roop+=2
                    ans+=1
            else:
                break
        
        print(ans)
    