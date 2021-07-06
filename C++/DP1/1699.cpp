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

    for (int i = 0; i <= n; i++)
    {
        dp[i] = i;
    }
    dp[1] = 1; // 1^2
    dp[2] = 2; // 1+1
    dp[3] = 3; // 1+1+1
    dp[4] = 1; // 2^2

    for (int i = 5; i <= n; i++)
    {

        for (int j = 1; j * j <= i; j++)
        {

            int k = j * j; // j*j가 i 보다 작거나 같으면
            if (i >= (k))
            {
                dp[i] = min(dp[i], dp[i - k] + 1); // 1==j*j  +  i-(j*j)일 때 최솟 값
            }
            else // k가 i를 넘으면 그냥 , j로 비교한다
            {
                dp[i] = min(dp[i], dp[i - j] + dp[j]);
            }
        }
    }
    cout << dp[n];
}
