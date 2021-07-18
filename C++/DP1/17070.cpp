#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 1025
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

typedef struct _DIR
{
    const int y, x;
} dir, *pdir;

dir move_[3] = {{0, 1}, {1, 0}, {1, 1}}; //가로 세로 대각 선
int n, m, c1, c2;
int r1, r2;
int result;
int dp[MAX][MAX];
int arr[MAX][MAX];
void DFS(const int &r, const int &c, const int state)
{
    if (r == n && c == n)
    {
        result++;
        return;
    }
    else
    {
        for (int i = 0; i < 3; i++)
        {
            // i=0 가로 , i=1 세로 ,i=2 대각선
            int next_x = c + move_[i].x;
            int next_y = r + move_[i].y;

            if ((i == 0 && state == 1) || (i == 1 && state == 0))
            { // 가로 -> 세로, 세로 -> 가로 불가능 continue; }
                continue;
            }
            if (next_y > n || next_x > n || arr[next_y][next_x] == 1)
            { // 범위를 벗어나거나, 벽일 경우
                continue;
            }
            if (i == 2 && (arr[r][c + 1] == 1 || arr[r + 1][c] == 1)) // i==2 대각선 일경우 ,가로 세로 확인해야함
            {
                // 대각선인 경우, 확인해야할 벽
                continue;
            }
            DFS(next_y, next_x, i); //재귀
        }
    }
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
        }
    }

    DFS(1, 2, 0);
    cout << result;
}
