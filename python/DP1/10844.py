import sys
sys.setrecursionlimit(2500)
LMIT = 101
MOD=1000000000
dp = [[0]*11 for _ in range(LMIT)] # 11인 이유는 j가 9일 때 j+1 =10 이므로 여유 공간 남겨놈


if __name__ == "__main__":
    n = int(input())
    #dp[N][L]= 길이가 N일 때 마지막 수가 L일 경우 계단의 수
    for i in range(1,10):
        dp[1][i]=1 #길이가 1일 때 마지막 수가 1~9일 때는 모두 계단 수
    
    
    for i in range(2,n+1):
        for j in range(0,10):
            if (j==0): # 현재길이에(i)서 마지막 수가 0일 때 계단 수가 되려면,그 전 길이(i-1)에서 마지막 숫자가 1일 때만 가능하다
                dp[i][0]=dp[i-1][1]
            else: #마지막 수가 0이아닌 모든 수는 그전 길이에서 앞뒤로 +-1씩 합치면됨
                #ex)  길이가 2일 때 j=2일 때  그 전 길이(1)일때 1과 3가 필요
                ## x2 ->  12(dp[i-1][j-1]) 32(d[i-1][j+1])
                dp[i][j]=(dp[i-1][j-1]+dp[i-1][j+1])%MOD # j가 9일 때 j+1=10 이 되기 때문에 위에서 배열 길이를 11로 설정,인덱스 10을 참조해도 초기화를 안해서 어차피 0
    sum_v=0
    for i in range(0,10):
        sum_v+=dp[n][i]
    
    print(sum_v%MOD)

