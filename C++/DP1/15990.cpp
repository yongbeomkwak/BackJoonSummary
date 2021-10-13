#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
#define MAX 100001
#define endl "\n"
#define tab " "
#define MOD 1000000009
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

int tc, n;
ull dp[MAX][4];
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //dp[i][j] = 끝이 j로 끝낫을 때 i를 만들 수 있는 경우의 수 
    dp[1][1] = 1;
    dp[2][2] = 1;
    dp[3][1] = 1;
    dp[3][2] = 1;
    dp[3][3] = 1;
    for (int i = 4; i < MAX; i++)
    {
        dp[i][1] = (dp[i - 1][2] + dp[i - 1][3])%MOD; // i를 만들고 끝이 1일 수 있는 경우는 바로 직전(i-1)이 2 또는 3 으로 끝나면 됨
        dp[i][2] = (dp[i - 2][1] + dp[i - 2][3])%MOD;
        dp[i][3] = (dp[i - 3][1] + dp[i - 3][2])%MOD;
    }
    cin >> tc;
    while (tc--)
    {
        cin >> n;
        ull ans = 0;
        ans = (dp[n][1] + dp[n][2] + dp[n][3])%MOD;
        cout << ans << endl;
    }
}
