import sys
sys.setrecursionlimit(2500)
LMIT=501
in_list=[]
dp=[[0]*LMIT for _ in range(LMIT)]
if __name__ == "__main__":
    n=int(input())
    for _ in range (n):
        in_list.append(list(map(int,input().split())))
    dp[0][0]=in_list[0][0] #첫 값은 미리 넣어줌 
    
    
    for i in range(n):
        for j in range(i+1):
            if(j==0):
                dp[i][j]=dp[i-1][j]+in_list[i][j]
            elif (j==i):
                dp[i][j]=dp[i-1][j-1]+in_list[i][j]
            else:
                dp[i][j]=max(dp[i-1][j-1],dp[i-1][j])+in_list[i][j]
    
    ans=max(dp[n-1])
    print(ans)
    




    

    





