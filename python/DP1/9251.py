import sys
sys.setrecursionlimit(2500)
LMIT = 1001
dp = [ [0]*LMIT for _ in range(LMIT)]
a=""
b=""


    


if __name__ == "__main__":
    a= input()
    b= input()
    
    for i in range(1,len(a)+1):
        for j in range(1,len(b)+1):
            if(a[i-1]==b[j-1]):
                dp[i][j]=dp[i-1][j-1]+1
            else:
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]) #A문자열 그전 것, 또는 B문자열 그 전 만들었던 것중 최대값

    print(dp[len(a)][len(b)])

            

  
    





