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
#define MAX 1001
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

int n, m, use_m = 0;
int dp[MAX][10001]; //dp[i][j] : i번째 앱까지 확인했을 때 j의 비용으로 얻을 수 있는 최대의 메모리.
int arr[MAX];
int cost[MAX];
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> cost[i];
        use_m += cost[i];
    }

    //dp[i][j] : i번째 앱까지 확인했을 때 j의 비용으로 얻을 수 있는 최대의 메모리.

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= use_m; j++) // 0부터 현재 총 사용  매모리양
        {
            if (j - cost[i] >= 0) // j 비용응 사용하여 최대 사용 메모리량 , 현재 사용 가능한 비용(j)보다 현재 실행하려는 앱의 비용(cost[i])이 작거나 같을경우
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[i]] + arr[i]); //현재 값과,이전 단계 비용(j-cost[i])  에 +해당 앱의 사용 메모리(arr[i])를 더해준다
            }
            dp[i][j] = max(dp[i][j], dp[i - 1][j]); //이전 앱까지  단계의 같은 비용과 비교
        }
    }

    for (int i = 0; i <= use_m; i++)
    {
        if (dp[n][i] >= m) //해당 메모리 기준 m 보다  최초로 크거나 같을 경우
        {
            cout << i << endl; // 해당 비용(i)출력
            break;
        }
    }
}
