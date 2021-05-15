import sys
sys.setrecursionlimit(2500)
LMIT=301
in_list=[0 for _ in range(LMIT)]
dp=[0 for _ in range(LMIT)]
if __name__ == "__main__":
    n=int(input())
    for _ in range (n):
        in_list.append(int(input()))
    
    dp[0]=in_list[0]
    dp[1]=in_list[0]+in_list[1]
    dp[2]=max(in_list[0]+in_list[2],in_list[1]+in_list[2])

    for i in range(3,n):
        dp[i]=max(dp[i-2]+in_list[i],dp[i-3]+in_list[i-1]+in_list[i])
    
    print(dp[n-1])
    
    




    

    





