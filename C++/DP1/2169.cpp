#include <bits/stdc++.h>

using namespace std;

#define MAX 1001
#define INF 9876543

int n, m;
int dp[MAX][MAX];
int gmap[MAX][MAX];
int Right[MAX] = {
    0,
};
int Left[MAX] = {
    0,
};
int ans = 0;

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> gmap[i][j];
        }
    }
    dp[0][0] = gmap[0][0];

    for (int i = 1; i < m; i++) // 0번 째 행은 오른쪽 이동으로만 더해짐
    {
        dp[0][i] += dp[0][i - 1] + gmap[0][i];
    }

    for (int i = 1; i < n; i++)
    {
        //왼쪽에서 오른쪽으로
        Right[0] = dp[i - 1][0] + gmap[i][0]; //첫 right[0]= dp[i-1][0](바로 위) + map[i][0]

        for (int j = 1; j < m; j++)
        {
            Right[j] = max(Right[j - 1], dp[i - 1][j]) + gmap[i][j]; // (왼쪽 값,위에서 내려온 값)최댓값 + map
        }

        Left[m - 1] = dp[i - 1][m - 1] + gmap[i][m - 1]; //왼쪽에서 오른쪽으로

        for (int j = m - 2; j >= 0; j--)
        {
            Left[j] = max(Left[j + 1], dp[i - 1][j]) + gmap[i][j]; //(오른쪽 값,위에서 내려오는 값)최댓값 +map
        }

        for (int k = 0; k < m; k++)
            dp[i][k] = max(Right[k], Left[k]); //해당 열의  왼쪽, 오른쪽 중 큰값 을 넣어준다.
    }

    cout << dp[n - 1][m - 1];
}
