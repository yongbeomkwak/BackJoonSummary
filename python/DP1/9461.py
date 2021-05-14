import sys
sys.setrecursionlimit(2500)

LMIT=1001
dp=[0 for _ in range(LMIT)]
if __name__ == "__main__":
    dp[1]=1
    dp[2]=1
    dp[3]=1
    tc=int(input())
    for _ in range(tc):
        n=int(input())
        for i in range(4,n+1):
            dp[i]=dp[i-3]+dp[i-2]
        print(dp[n])    



