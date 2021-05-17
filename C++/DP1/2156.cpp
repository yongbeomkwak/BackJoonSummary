#include <iostream>

#define LMIT 10001
int dp[LMIT];
int in_list[LMIT];
using namespace std;

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &in_list[i]);
    }
    dp[1] = in_list[1];
    if (n > 1) //1보다 클 때만 인덱스 2 접근 할 수 있으므로
    {
        dp[2] = dp[1] + in_list[2];
    }

    for (int i = 3; i <= n; i++)
    {
        //dp[i]=현재 까지 먹은 와인 점수
        //경우1: 연속 1번 먹기(두번째 전(i-2)+i(현재))
        //경우2: 연속 2번 먹기(3번째전(i-3)+(i-1)+i))
        //경우3: 연속 0번 먹기 max(dp[i],dp[i-1]) 안 먹으니 그 전 결과 그대로 가져오기
        dp[i] = max(dp[i - 2] + in_list[i], dp[i - 3] + in_list[i - 1] + in_list[i]);
        dp[i] = max(dp[i], dp[i - 1]);
    }
    printf("%d\n", dp[n]);
}