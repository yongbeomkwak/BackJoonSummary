#include <iostream>

#define LMIT 101
#define MOD 1000000000

int dp[LMIT][11]; //# 11인 이유는 j가 9일 때 j+1 =10 이므로 여유 공간 남겨놈
using namespace std;
int main()
{
    int n = 0;
    scanf("%d", &n);
    // #dp[N][L]= 길이가 N일 때 마지막 수가 L일 경우 계단의 수
    for (int i = 1; i <= 9; i++)
    {
        dp[1][i] = 1; // #길이가 1일 때 마지막 수가 1~9일 때는 모두 계단 수
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            if (j == 0) // # 현재길이에(i)서 마지막 수가 0일 때 계단 수가 되려면,그 전 길이(i-1)에서 마지막 숫자가 1일 때만 가능하다
            {
                dp[i][0] = dp[i - 1][1];
            }
            else
            {
                // #마지막 수가 0이아닌 모든 수는 그전 길이에서 앞뒤로 +-1씩 합치면됨
                // #ex)  길이가 2일 때 j=2일 때  그 전 길이(1)일때 1과 3가 필요
                // ## x2 ->  12(dp[i-1][j-1]) 32(d[i-1][j+1])
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD; //  # j가 9일 때 j+1=10 이 되기 때문에 위에서 배열 길이를 11로 설정,인덱스 10을 참조해도 초기화를 안해서 어차피 0
            }
        }
    }
    long long sum = 0;
    for (int i = 0; i <= 9; i++)
    {
        sum += dp[n][i];
    }
    sum %= MOD;
    printf("%lld", sum);
}