#include <iostream>

#define LMIT 1000
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
    int len = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &in_list[i]);
    }

    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (in_list[i] > in_list[j])
            {
                // j 까지 카운팅(dp[j]) +1 보다 작으면  +1한 값으로 바꿈
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    printf("%d", ans);
}