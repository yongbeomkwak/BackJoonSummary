#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 1001
#define endl "\n"
typedef pair<int, int> pai;
typedef vector<int>::iterator iter;
typedef unsigned long long ull;

int max(const int &a, const int &b)
{
    return a > b ? 1 : 0;
}

int min(const int &a, const int &b)
{
    return a < b ? a : b;
}

bool comp(const int &a, const int &b)
{
    return a > b;
}
int n, m;
int dp[MAX][MAX];
int map[MAX][MAX];
int x_move[4] = {0, 0, -1, 1}; //상하좌우(x는 상하 일 때 0)
int y_move[4] = {-1, 1, 0, 0}; //상하좌우(y는 좌우 일 때 0)

int DFS(const int &y, const int &x)
{
    if (y == m && x == n) //y 행 // x 열
    {
        return 1;
    }
    else if (dp[y][x] == -1)
    {
        dp[y][x] = 0; // 들렀으므로  -1(초기화) -> 0 으로
        for (int i = 0; i < 4; i++)
        {
            int next_y = y + y_move[i];
            int next_x = x + x_move[i];
            if ((next_x > 0 && next_y > 0) && (next_x <= n && next_y <= m) && map[next_y][next_x] < map[y][x])
            // 다음 좌표가 (0,0) 보다 크고 ,(n,m) 목적지 안에 있고, 내리막, 즉 다음 next_ 들의 값이 현재 y,x 보다 작으면
            {
                dp[y][x] += DFS(next_y, next_x); //다음으로 이동 , Top to Bottom 느낌
            }
        }
    }
    return dp[y][x]; // Top to Bottom
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> m >> n;
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = -1; // -1은 아직 지나지 않았다는 뜻 (DFS는 들렸는지 안들렸는지 표시해줘야함)
            map[i][j] = MAX;
        }
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> map[i][j];
        }
    }
    cout << DFS(1, 1);
}
