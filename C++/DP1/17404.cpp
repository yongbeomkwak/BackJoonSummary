#include <bits/stdc++.h>

using namespace std;

#define MAX 1001
#define INF 9876543

int arr[MAX][3];
int dp[MAX][3];
int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    int ret = INF;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    // R:0, G:1, B:2

    for (int i = 0; i < 3; i++)
    {

        for (int k = 0; k < 3; k++)
        {
            if (i == k)
                dp[1][k] = arr[1][k]; //현재 출발인 i만 재대로 된 출발 값
            else
                dp[1][k] = INF; //나머지는 최대값으로 출발
        }

        for (int i = 2; i <= n; i++)
        {
            dp[i][0] = arr[i][0] + min(dp[i - 1][1], dp[i - 1][2]); //현재 R을 선택했으므로 이전 선택은 G와 B중 최솟값 선택
            dp[i][1] = arr[i][1] + min(dp[i - 1][0], dp[i - 1][2]); //현재 G를 선택했으므로 이전 선택은 R과 B중 최솟값 선택
            dp[i][2] = arr[i][2] + min(dp[i - 1][0], dp[i - 1][1]); //현재 B를 선택했으므로 이전 선택은 R과 G중 최솟값 선택
        }

        for (int k = 0; k < 3; k++)
        {
            if (i != k) //처음과 끝은 달라야함
                ret = min(ret, dp[n][k]);
        }
    }

    cout << ret;
}
