#include <bits/stdc++.h>

using namespace std;

#define MAX 1500001
#define INF 9876543

int n;
int t[MAX] = {
    0,
};
int p[MAX] = {
    0,
};
int dp[MAX] = {
    0,
};
int ans = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> t[i] >> p[i];
    }
    int currMAX = 0;
    for (int i = 0; i <= n; i++)
    {
        currMAX = max(currMAX, dp[i]);
        if (i + t[i] > n)
            continue; //현재일 + 해당업무 일수 > n 이면 작업 불가

        dp[i + t[i]] = max(dp[i + t[i]], currMAX + p[i]); //다음 작업=max(다음작업,현재 최대값+현재작업 페이)

        ans = max(ans, dp[i + t[i]]);
    }

    cout << ans;
}
