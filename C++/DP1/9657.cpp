#include <bits/stdc++.h>

using namespace std;

#define MAX 1001

int dp[MAX];
int n;

int main()
{
    cin >> n;
    dp[1] = 1; // 1:상근이 승리 ,0:창영이 승리
    dp[2] = 0;
    dp[3] = 1;
    dp[4] = 1;
    for (int i = 5; i <= n; i++)
    {
        if ((dp[i - 1] + dp[i - 3] + dp[i - 4]) == 3)
            dp[i] = 0; //이전 상황에서 모두 상근이 이기면, 현재는 창영이 승리
        else
            dp[i] = 1; //하나라도 상근이가 이길 상황이 있으면 상근의 승리
    }

    if (dp[n])
        cout << "SK";
    else
        cout << "CY";
}