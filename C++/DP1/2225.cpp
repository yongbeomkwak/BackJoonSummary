#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 201
#define endl "\n"
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

int dp[MAX][MAX]; // dp[k][n]= k개를 사용하여 n을 만들 수 있는 경우의 수
                  // dp[k-1][n-1]= k-1개를 사용하여 n-1을 만들 수 있는 경우의 수

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k; //k개를 더하여(0~n)부터  n을 만듬
    //  0~(n,k)~200
    //(x+y)^k=n    (0+n)^k
    // k=3  n=2
    // k=0 n=1

    for (int i = 0; i <= n; i++)
        dp[1][i] = 1; // 1가지 수를 이용하여 i를 만들 수 있는 경우의 수 , 자기자신 (1가지)

    for (int i = 0; i <= k; i++)
        dp[i][0] = 1; // i가지 수를 이용하여 0을 만들 수 있는 경우의 수 0 만 더함 1가지

    for (int i = 2; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // i개르 합하여 j를 만들 수 있는 경우 의 수는
            // i-1개를 더하여 j를 만들 수 있는 경우의수 + i개를 더하여  j-1을 만드는 수
            //즉 dp[i][j]=dp[i-1][j]+dp[i][j-1]
            //  dp[2][3]= dp[1][3] + dp[2][2]
            // 2개를 합하여 3 을 만드는 경우의 수는 , 1개로 3을 만드는 경우 + 2개로 2를 만드는 경우의 수
            // (1 2) (2 1) 2=   ,   1(3) +  1(1,1)
            // 4 2
            // (1,3) (3,1) (2,2) 3= ,   1(4)  +  2(1,2) (2,1)

            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
        }
    }
    cout << dp[k][n] << endl;
}
