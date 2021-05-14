import sys
sys.setrecursionlimit(2500)
in_list=[]
dp=[[0]*3 for _ in range(1000)]
if __name__ == "__main__":
    n=int(input())
    for _ in range (n):
        in_list.append(list(map(int,input().split())))
    dp[0][0]=in_list[0][0] #첫 값은 미리 넣어줌 
    dp[0][1]=in_list[0][1]
    dp[0][2]=in_list[0][2]
    # [i][0] = Red, [i][1]= Green, [i][2]=Blue

    #DP Bottom up 방식 사용 
    for i in range(1,n): #1부터 시작 
        #i=1 일 때 
        #dp[1][0]=2번째 까지 찾은 최솟값(단 현재 더한 값은 Red(0))
        #dp[1][0]=그전에(Green,Blue)중  작은값 + 현재 R(Red)  값이된다
        #dp[1][1]=그전에(Red,Blue)중  작은값 + 현재 G(Green)  값이된다
        #dp[1][2]=그전에(Red,Green)중  작은값 + 현재 B(Blue)  값이된다
        dp[i][0]=min(dp[i-1][1],dp[i-1][2])+in_list[i][0]
        dp[i][1]=min(dp[i-1][0],dp[i-1][2])+in_list[i][1]
        dp[i][2]=min(dp[i-1][0],dp[i-1][1])+in_list[i][2]
    #n-1까지 돌면 모두 다 돈 것 
    min_val=9999999
    for i in range(3):
        if(min_val>dp[n-1][i]):
            min_val=dp[n-1][i]
    
    print(min_val)
    




    

    





