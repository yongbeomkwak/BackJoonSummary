import sys
sys.setrecursionlimit(2500)
LMIT = 10001
dp = [ 0 for _ in range(LMIT)]
in_list =[ 0 for _ in range(LMIT)]

if __name__ == "__main__":
    n = int(input())
    
    for i in range(1,n+1):
        in_list[i]=int(input())

    dp[1]=in_list[1]
    if n>1:
        dp[2]=dp[1]+in_list[2]

    for i in range(3,n+1):
        dp[i]=max(dp[i-1],dp[i-2]+in_list[i],dp[i-3]+in_list[i-1]+in_list[i])

    print(dp[n])

   

