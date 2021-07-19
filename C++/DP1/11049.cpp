#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 501
#define endl "\n"
#define tab " "
#define MOD 9901
typedef pair<int, int> pai;
typedef vector<int>::iterator iter;
typedef unsigned long long ull;

typedef struct RC
{
    int r, c;
} rc;

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
int arr[MAX][2];
int n;
int dp[MAX][MAX];
int solve(const int &s, const int &e)
{
    int ret = 0;
    if (s == e)
        return 0;
    if (dp[s][e])
        return dp[s][e];
    if (e == s + 1) //현재 s 다음이 바로 e일 경우
    {
        ret = arr[s][0] * arr[s][1] * arr[e][1]; // A*B = A[0]*A[1]*B[1]  행렬 계산 , 3X2 2X5 => 3X2X5
        dp[s][e] = ret;                          //저장
        return dp[s][e];
    }
    for (int i = s; i <= e; ++i)
    {

        // (s)부터 i 까지 와  i+1 부터 e까지, 분할 정복 이용  ,    + 가장 처음 행렬의 행  * 현재 행렬의 열 , 마지막 행렬의 열 (AXBXC) -> A[0]
        ret = solve(s, i) + solve(i + 1, e) + arr[s][0] * arr[i][1] * arr[e][1];
        if (!dp[s][e] || ret < dp[s][e])
            dp[s][e] = ret;
    }
    return dp[s][e];
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i][0] >> arr[i][1];
    }
    cout << solve(1, n);
}
