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

int n;
int dp[MAX];
int arr[MAX];
int correct[MAX];

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        dp[i] = 1;
    }

    //dp[i]=i 까지 가장 큰 증가 수열
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1) // LIS 이용 (뒤에 것이 앞 것보다 커야하고,누적 길이가 가장 긴 것을 사용해야함)
            //  만약 10 20 10 30 일 때 30을 기준으로 LIS 구할 때 dp[i]<dp[j]+1 이 없으면 20>10 이 되므로  다시 길이가 작아짐 
            {
                dp[i] = dp[j] + 1;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (ans < dp[i])
        {
            ans = dp[i];
        }
    }
    cout << n - ans;
}
