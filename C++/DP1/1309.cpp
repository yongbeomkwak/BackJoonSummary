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
#define endl "\n"
#define tab " "
#define MOD 9901
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
int n;

int dp[MAX];

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    dp[0] = 1, dp[1] = 3;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = (dp[i - 1] * 2 + dp[i - 2]) % MOD;
    }
    cout << dp[n];
}
