#include <bits/stdc++.h>

using namespace std;

using namespace std;

int tc, n;

long long dp[65][11]; // dp[i][j] :길이 i,마지막 수 j일 때

int main()
{

    for (int i = 0; i < 10; i++) //길이 1일 때,마지막 수 상관없이 경우는 1이다.
    {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= 64; i++) //길이
    {
        for (int j = 0; j <= 9; j++) //마지막 숫자
        {
            for (int k = j; k <= 9; k++)
            {
                dp[i][j] += dp[i - 1][k]; //현재 길이 i이고 끝이 j일 때 , 모든 경우는 길이 i-1일 때 마지막수가 0~j까지 이다.
            }
        }
    }

    cin >> tc;
    while (tc--)
    {
        cin >> n;
        long long ret = 0;
        for (int i = 0; i <= 9; i++) //길이 n에 대하여 끝나는 수가 0~9까지 모든 수 합함
        {
            ret += dp[n][i];
        }
        cout << ret << "\n";
    }
}