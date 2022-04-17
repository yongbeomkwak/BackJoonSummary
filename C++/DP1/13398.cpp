#include <bits/stdc++.h>

using namespace std;

#define MAX 100001
#define INF 9876543

int n;
int dp[MAX][2]; // i~n까지
int arr[MAX] = {
    0,
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    dp[1][0] = arr[1];
    dp[1][1] = arr[1];
    int ans = arr[1];

    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = max(arr[i], dp[i - 1][0] + arr[i]);       //현재 것부터 시작하거나 , 이전꺼와 합치거나
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + arr[i]); //현재거를 건너뛰거나 ,이전꺼와 합치거나
        ans = max(ans, max(dp[i][0], dp[i][1]));
    }

    cout << ans;
}
