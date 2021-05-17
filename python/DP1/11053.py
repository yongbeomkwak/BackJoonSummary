import sys
sys.setrecursionlimit(2500)
LMIT = 1000
dp = [ 1 for _ in range(LMIT)]
#in_list =[]

if __name__ == "__main__":
    n = int(input())
    
    in_list=list(map(int,input().split()))
    ans=1
    for i in range(n):
        for j in range(i+1):
            if in_list[i]>in_list[j]:
                dp[i]=max(dp[i],dp[j]+1)
        
        ans=max(ans,dp[i])
    print(ans)

   

