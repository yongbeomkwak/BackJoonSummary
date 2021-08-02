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
int min(const int &a, const int &b)
{
    return a < b ? a : b;
}

bool comp(const int &a, const int &b)
{
    return a > b;
}
int n, k;
int dp[MAX][MAX];
int fact[MAX];
int factorial(int n)
{
    if (fact[n])
    {
        return fact[n];
    }
    else
    {
        for (int i = 2; i <= n; i++)
        {
            fact[i] = (fact[i - 1] * i) % 10007;
        }
        return fact[n];
    }
}

int Binomial_coefficient(int &n, int &r)
{
    if (n == 1 || n == r)
    {
        return 1;
    }
    else
    {
        return (fact[n] / (fact[r] * fact[n - r]) % 10007);
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    if (n == 0)
    {
        //N = 0 인 경우에는 N - 1 값에 음수가 발생하기 때문에 계산이 제대로 될 수가 없다       또한, 계산을 해보지 않아도, N = 0이라면, [N K] 의 값은 0이 된다.

        cout << 1 << endl;
    }
    else
    {
        //dp[n][k]= (n k) (n!/(k!(n-k)!) -> (파스칼의 법칩)  (n k)=(n-1 k-1)+(n-1 k)
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= k; j++)
            {
                if (j == 0) //  n!/(k!(n-k)!) == 1
                    dp[i][j] = 1;
                else if (i == j) //n!/(k!(n-k)!) == 1
                    dp[i][j] = 1;
                else
                    //dp[n][k]= (n k) (n!/(k!(n-k)!) -> (파스칼의 법칩)  (n k)=(n-1 k-1)+(n-1 k)
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                dp[i][j] = dp[i][j] % 10007;
            }
        }
        cout << dp[n][k] % 10007 << endl;
    }
}
