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

int n, s, m;
int dp[MAX][1001];
int arr[MAX];

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> s >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    //dp[n][i] = n번 째 곡일 때 i 볼륨 가능 여부
    dp[0][s] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (!dp[i - 1][j]) // 이전 곡이 j 볼륨일 수 없으면  넘어감
            {
                continue;
            }
            if (j + arr[i] <= m) //m 보다 작으면
            {
                dp[i][j + arr[i]] = 1; //가능
            }
            if (j - arr[i] >= 0) //0보다 크면
            {
                dp[i][j - arr[i]] = 1; //가능
            }
        }
    }
    int ans = -1;
    for (int i = m; i >= 0; i--)
    {
        if (dp[n][i])
        {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
}
