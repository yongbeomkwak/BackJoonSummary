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
int dp[MAX];
int seq[MAX];
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> seq[i];
    }
    int max_v = 0;
    //dp[a]=b   a인덱스 까지 구한 가장 큰 증가 수열 값이 b
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 1;
        for (int j = 1; j <= i; j++)
        {
            if (seq[j] > seq[i] && dp[i] < dp[j] + 1) //만약 i 전에  i보다 작은 원소들이 있다, 즉 증가할 부분이 있고,현재 dp 값이, 전 dp들 +seq가 더 클 경우 업데이트
            {
                dp[i] = dp[j] + 1;
            }
            if (max_v < dp[i])
                max_v = dp[i];
        }
    }
    cout << max_v << endl;
}
