#include <bits/stdc++.h>

using namespace std;

#define MAX 1001
int w, t;
int arr[MAX] = {
    0,
};
int dp[31][2][MAX]; // dp[이동횟수][위치][시간]
int main()
{
    cin >> t >> w;
    for (int i = 1; i <= t; i++)
    {
        cin >> arr[i];
    }

    for (int j = 0; j <= w; j++) //움직임 횟수
    {
        for (int i = 1; i <= t; i++) //시간
        {
            if (j == 0) //한번도 안움직였다면
            {
                dp[j][0][i] = dp[j][0][i - 1] + (arr[i] == 1); //움직임 0인,바로 전 시간 +현재 사과 받을 수 있으면 +1, 아니면 +0
            }
            else
            {
                //이전 타임에 그대로 있을 때, 이전 타임에 이동 했을 때 중(이동횟수-1,시간-1) 최댓값
                dp[j][0][i] = max(dp[j][0][i - 1] + (arr[i] == 1), dp[j - 1][1][i - 1] + (arr[i] == 1));
                dp[j][1][i] = max(dp[j][1][i - 1] + (arr[i] == 2), dp[j - 1][0][i - 1] + (arr[i] == 2));
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            ans = max(ans, dp[j][i][t]);
        }
    }

    cout << ans;
}
