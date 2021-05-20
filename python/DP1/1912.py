import sys
sys.setrecursionlimit(2500)
LMIT = 100000
dp = [ 0  for _ in range(LMIT)]



    


if __name__ == "__main__":
    n=int(input())
    in_list=list(map(int,input().split()))
    dp[0]=in_list[0]
    result=dp[0]
    for i in range(1,n):
        dp[i]=max(dp[i-1]+in_list[i],in_list[i])
        result=max(result,dp[i])
    
    print(result)
    
    

            





