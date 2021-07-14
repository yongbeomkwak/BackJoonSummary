#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 501
#define endl "\n"
#define tab " "
#define MOD 9901
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
int n, k;
int dp[MAX][MAX];
int forest[MAX][MAX];
int x_move[4] = {0, 0, -1, 1};
int y_move[4] = {-1, 1, 0, 0}; //상 하 좌 우
int DFS(const int &y, const int &x)
{
    if (dp[y][x] != 0)
    {
        return dp[y][x];
    }
    dp[y][x] = 1;
    for (int i = 0; i < 4; i++)
    {
        int next_x = x + x_move[i];
        int next_y = y + y_move[i];
        if ((next_x > 0 && next_x <= n) && (next_y > 0 && next_y <= n))
        {

            if (forest[y][x] < forest[next_y][next_x])
            {
                dp[y][x] = max(dp[y][x], DFS(next_y, next_x) + 1);
            }
        }
    }

    return dp[y][x];
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> forest[i][j];
            dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            ans = max(ans, DFS(i, j));
        }
    }
    cout << ans;
}
