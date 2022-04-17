#include <bits/stdc++.h>

#define MAX 100001
#define INF 987654321
using namespace std;

int dp[MAX] = {
    0,
};
int main()
{
    int n;

    cin >> n;

    dp[1] = INF;
    dp[2] = 1;
    dp[3] = INF;
    dp[4] = 2;
    dp[5] = 1;

    for (int i = 6; i <= n; i++)
    {
        if (dp[i - 2] == INF && dp[i - 5] == INF)
        {
            dp[i] = INF;
            continue;
        }

        dp[i] = 1 + min(dp[i - 2], dp[i - 5]);
    }

    if (dp[n] == INF)
        cout << -1;
    else
        cout << dp[n];
}
