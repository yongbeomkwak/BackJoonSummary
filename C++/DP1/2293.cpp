#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 10001
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
    cin >> n >> k;
    int coins[n];

    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    dp[0] = 1; // 0원을 만들 수 있는 방법은 하나
    //dp[j]=기존의 동전 종류를 이용해 k를 만드는 경우의 수
    for (int i = 0; i < n; i++) // 모든 동전을 돌며
    {
        for (int j = coins[i]; j <= k; j++) //j는 만들고 싶은 금액
        // x원'짜리를 이용해서 어떤 금액을 만들려면, 최소한 그 금액은 x원보다 크거나 같아야 한다는 것이다.
        //즉 1부터 하면 낭비

        {
            if (j - coins[i] >= 0) //현재 가치 만들 가치 j가 사용할 코인보다 작으면 , 사용 불가
                dp[j] += dp[j - coins[i]];
            /* DP[3] += DP[2]가 된다. 왜 ? 현재 '1'원을 이용해서 3원을 맞추려면, 기존에 2원이 있어야 하고, 이 2원을 만드는 방법은 DP[2]에 저장되어 있기 때문이다.
            즉 ! 현재 X원인 동전을 가지고 있다면, 이 동전을 이용해서 Y원을 만들고 싶다면, DP[Y] = DP[Y] + DP[Y - X]가 된다. 
            그 동전이 가진 가치만큼을 뺀 나머지 액수를 만드는 경우의 수가 더해진다는 것이다.
            */
        }
    }
    cout << dp[k];
}
