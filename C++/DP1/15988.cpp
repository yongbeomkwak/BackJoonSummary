#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 1000001
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

int n, t;
long long dp[MAX];

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    /*
    1  1 1 1
    1  2 1
    1  1 2
    1  3
    2  1 1
    2  2
    3 1
    */
    for (int i = 4; i <= MAX; i++)
    {

        dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % MOD;
    }
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << (dp[n] % MOD) << "\n";
    }
}
