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
int coins[101];
int dp[MAX];
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;

    for (int i = 1; i <= k; i++)
    {
        dp[i] = MAX; //dp[0]=0 나머지는 최대값 10001로 초기화
    }
    //dp[a] =b  a까지의 동전을 사용하여 k를  만들 수 잇는 최소 개수 b
    for (int i = 1; i <= n; i++)
    {
        cin >> coins[i];                    //코인 입력받기
        for (int j = coins[i]; j <= k; j++) // coin[i]=5 ,k=15 일 때 , dp[5-5]+1== dp[0]+1 , min(5,1) - > 1
        {
            dp[j] = min(dp[j], dp[j - coins[i]] + 1); //  j-coin[i]에서 coin[i]를 더해만든 동전의 수
        }
    }
    if (dp[k] == MAX)
        cout << -1 << endl; //만약 최대값이랑 같으면  -1(불가능)
    else
        cout << dp[k] << endl;
}
