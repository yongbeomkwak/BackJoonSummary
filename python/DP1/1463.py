import sys
sys.setrecursionlimit(2500)
LMIT = 1000001
in_list = [0 for _ in range(LMIT)]
dp = [0 for _ in range(LMIT)]


if __name__ == "__main__":
    n = int(input())


# N이라는 수는 N//3을 연산전으로 돌리면, 즉 +1을 하면 만들 수 있다.
# N이라는 수는 N//2을 연산전으로 돌리면, 즉 +1을 하면 만들 수 있다.
# N이라는 수는 N-1을 연산전으로 돌리면, 즉 +1을 하면 만들 수 있다.
# 따라서 !!! 점화식 : dp(N) = min ( dp(N//3) +1, dp(N//2)+1 , dp(N-1)+1 )
# dp라는 배열의 index는 문제의 입력n과 대응하고, index의 값은 연산최솟값(문제의 출력)에 대응하게된다.
# Bottom up  방식   dp[0]=0, dp[1]=0 ,1~N까지 가봄 
    for i in range(2, n+1):
        dp[i] = dp[i-1] + 1

        if i % 2 == 0 and dp[i] > dp[i//2] + 1:
            dp[i] = dp[i//2]+1

        if i % 3 == 0 and dp[i] > dp[i//3] + 1:
            dp[i] = dp[i//3] + 1

    print(dp[n])
