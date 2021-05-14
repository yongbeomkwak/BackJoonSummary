import sys
sys.setrecursionlimit(2500)

LMIT=1000001
dp=[0 for _ in range(LMIT)]
if __name__ == "__main__":
    dp[1]=1
    dp[2]=2
    n=int(input())
    for i in range(3,n+1):
        dp[i]=(dp[i-1]+dp[i-2])%15746
    
    print(dp[n])




