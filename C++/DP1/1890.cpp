#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 101
#define endl "\n"
#define tab " "
#define MOD 1000000000
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
int n, k;

int arr[MAX][MAX];
ull dp[MAX][MAX]; // dp[k][n]= k개를 사용하여 n을 만들 수 있는 경우의 수
                  // dp[k-1][n-1]= k-1개를 사용하여 n-1을 만들 수 있는 경우의 수

ull DFS(const int &y, const int &x)
{
    //dp[y][x] - > (y,x)까지 올 수 있는 경로의 개수

    if (x == n && y == n)
    {
        return 1; //빈드시 1
    }
    else if (dp[y][x] == -1)
    {
        dp[y][x] = 0; // 반드시 0
        int next_y = y + arr[y][x];
        int next_x = x + arr[y][x];
        if (next_x <= n && next_y <= n) // 행 열 모두 여유 있을 때
        {
            dp[y][x] += DFS(next_y, x) + DFS(y, next_x);
        }
        else if (next_y <= n && next_x > n) //행만 여유 있을 때
        {
            dp[y][x] += DFS(next_y, x);
        }
        else if (next_y > n && next_x <= n) // 열만 여유 있을 때
        {
            dp[y][x] += DFS(y, next_x);
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

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = -1;
            cin >> arr[i][j];
        }
    }

    cout << DFS(1, 1);
}
