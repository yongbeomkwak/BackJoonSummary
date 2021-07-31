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
#define MAX 46
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

int n;
int dp[MAX][3];
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    //dp[i][1] -> i번 째 연산에 A의 개수,i번 째 연산의 B의 개수
    dp[0][1] = 1;
    dp[0][2] = 0;
    //dp[i][1] = dp[i-1][2] 이전 B의 개수
    //dp[i][2] = dp[i-1][1] +  dp[i-1][2] ,   이전 A개수 + 이전 B의 개수
    for (int i = 1; i <= n; i++)
    {
        dp[i][1] = dp[i - 1][2];
        dp[i][2] = dp[i - 1][1] + dp[i - 1][2];
    }

    cout << dp[n][1] << tab << dp[n][2];
}
