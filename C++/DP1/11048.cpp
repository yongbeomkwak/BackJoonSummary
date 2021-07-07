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
    return a > b ? a : b;
}
int max3(const int &a, const int &b, const int &c)
{
    int t = max(a, b);
    int k = max(b, c);
    return max(t, k);
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
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    int temp = 0, max_v = 0;

    for (int r = 1; r <= n; r++)
    {
        for (int c = 1; c <= m; c++)
        {
            cin >> temp;                                                //  해당 위치에 대한 캔디 값 입력 받고
            max_v = max3(dp[r - 1][c - 1], dp[r - 1][c], dp[r][c - 1]); // 해당 위치를 기준으로, 왼쪽 위,왼쪽,위,왼쪽  중 최대값 찾아냄
            dp[r][c] = temp + max_v;                                    // dp[r][c]=  r c 위치의 캔디 최대값
        }
    }
    cout << dp[n][m] << endl;
}
