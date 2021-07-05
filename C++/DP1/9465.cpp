#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 100001
typedef pair<int, int> pai;
typedef vector<int>::iterator iter;

int max(const int &a, const int &b)
{
    return a > b ? a : b;
}
int min(const int &a, const int &b)
{
    return a < b ? a : b;
}

bool comp(const int &a, const int &b)
{
    return a > b;
}
int N, T;
int sticker[2][MAX];
int main()
{

    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    while (T--)
    {
        cin >> N;
        int dp[2][MAX];
        for (int i = 0; i < 2; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                cin >> sticker[i][j];
            }
        }
        dp[0][0] = dp[1][0] = 0;  // 1~2번 째 줄 첫 열 모두 0 (내가 임의로 만드칸)
        dp[0][1] = sticker[0][1]; // 실제 값들을 오른쪽으로 하나씩 미뤄놈
        dp[1][1] = sticker[1][1]; // 1~2번 째 줄 2번 째 열부터 카운틴
        for (int i = 2; i <= N; i++)
        {
            dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + sticker[0][i]; //현재위치 까지 최대값은=max(한칸 전 대각선,두칸 전 대각선) + 현재 위치 스티커 값
            dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + sticker[1][i];
        }
        cout << max(dp[0][N], dp[1][N]) << "\n";
    }
}
