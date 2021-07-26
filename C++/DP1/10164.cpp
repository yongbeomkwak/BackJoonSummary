#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 16
#define endl "\n"
#define tab " "
#define MOD 9901
#define INF 987654321
typedef pair<int, int> pai;
typedef vector<int>::iterator iter;
typedef unsigned long long ull;

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

ull n, m, k;
ull dp[MAX][MAX];

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    int k_row = 0, k_col = 0;
    k_row = k % m != 0 ? k / m + 1 : k / m; // 행 위치
    k_col = k % m;                          // 열 위치
    for (int i = 1; i <= n; i++)
    {
        dp[i][1] = 1; // 1열 모두 1
    }
    for (int i = 1; i <= m; i++)
    {
        dp[1][i] = 1; //1행 모두 1
    }

    if (k == 0)
    {
        for (int i = 2; i <= n; i++)
        {
            for (int j = 2; j <= m; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1]; // 위에 꺼  왼쪽 꺼
            }
        }
    }
    else
    {

        for (int i = 2; i <= k_row; i++)
        {
            for (int j = 2; j <= k_col; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1]; // 위에 꺼  왼쪽 꺼
            }
        }

        for (int i = k_row; i <= n; i++)
        {
            dp[i][k_col] = dp[k_row][k_col]; // k열 모두 1
        }
        for (int i = k_col; i <= m; i++)
        {
            dp[k_row][i] = dp[k_row][k_col]; //k행 모두 1
        }
        for (int i = k_row + 1; i <= n; i++) // k_row 와 k_col 다음 부터 다시 왼쪽 위 더하기
        {
            for (int j = k_col + 1; j <= m; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    cout << dp[n][m] << endl;
}
