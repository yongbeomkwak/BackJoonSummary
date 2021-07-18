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

int n, m, c1, c2;
int r1, r2;
int dp[MAX][MAX];
int arr[MAX][MAX];
int sum[MAX][MAX]; // dp[]
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
            sum[i][j] += sum[i][j - 1] + arr[i][j]; //계속 누적합
        }
    }

    for (int i = 0; i < m; i++)
    {
        cin >> r1 >> c1 >> r2 >> c2;
        if (c1 == c2 && r1 == r2)
        {
            cout << arr[r1][c1] << endl;
        }
        else
        {
            for (int j = r1; j <= r2; j++)
            {
                dp[r2][c2] += (sum[j][c2] - sum[j][c1 - 1]); //점화식 해당 행 까지 정해진 구간 더힘
            }
            cout << dp[r2][c2] << endl;
            dp[r2][c2] = 0;
        }
    }
}
