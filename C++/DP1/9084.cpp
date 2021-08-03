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
#define MAX 10001
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

int n, tc, m;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> tc;

    while (tc--)
    {

        cin >> n;
        int coins[21] = {0};
        for (int i = 1; i <= n; i++)
        {
            cin >> coins[i]; // 동정들
        }
        cin >> m; //목표 금액
        int dp[MAX];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = coins[i]; j <= m; j++) //첫 번째 동전 부터
            {
                //dp[i]=i를 만들 수 있는 경우의 수
                //dp[2]= 2를 만들 수 있는 경우의 수
                //dp[j-coins[i]]= coins[i]를 더하기만 하면 j를 만들 수 있는 경우의 수
                //만약  동전이 2와 3 일  때 6을 만들어야 한다
                // 2로 dp[6]=1 한개 만듬
                // 3로 dp[6]=1 한개만듬
                // 총 2 개  dp[6]=2
                dp[j] += dp[j - coins[i]];
            }
        }
        cout << dp[m] << endl;
    }
}
