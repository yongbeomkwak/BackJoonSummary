#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 31
#define endl "\n"
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
int n, k;
int dp[MAX];

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 3;
    for (int i = 4; i <= n; i += 2) //짝수들만
    {
        for (int j = 2; j <= i; j += 2) //짝수들만
        {
            if (j == 2)
            {
                dp[i] = dp[i - 2] * 3; //  dp[2]값을 dp[i-2]에 3개의 위치에  넣을 수 있음 즉 dp[i-2]*3 ,,왼쪽 끝 오른쪽 끝 중간
            }
            else
            {
                dp[i] += dp[i - j] * 2; //  dp[i-j] i-j에    j를 2개의 위치에 넣을 수 있음 , 왼 오
            }
        }
    }
    cout << dp[n];
}
