#include <iostream>

using namespace std;

int score[301];
long long int dp[301];
int n = 0;

long long max(long long a, long long b)
{
    return a > b ? a : b;
}

int main()
{

    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &score[i]);
    }
    dp[1] = score[1];                                      // 첫번째 계단
    dp[2] = max(score[1] + score[2], score[2]);            //첫번째 계단 + 두번째 계단,두번째 계단 중 최대값
    dp[3] = max(score[1] + score[3], score[2] + score[3]); //첫번째 계단 + 세번째 계단, 두번째 계단 +세번째 계단

    //4번째 계단부터,
    //해당 계단의 최댓값은(dp[i])=해당 계단 전 전의 최대값 + 현재 계단 값(dp[i-2]+score[i]) 과 해당 계단의  3번 째 전 까지 최대값(dp[i-3]) + 해당 계단 바로 전(score[i-1]) + 현재계단(score[i]) 중 큰 값 선택
    //dp[i-2]+score[i] : 한번에 두번 오르기
    //dp[i-3]+score[i-1]+score[i]:연속해서 두번오르기(i-1,i)(그렇기 때문에 i-2 를 밞지 않음)
    for (int i = 4; i <= n; i++)
    {
        dp[i] = max(dp[i - 2] + score[i], dp[i - 3] + score[i - 1] + score[i]);
    }
    printf("%lld", dp[n]);
}