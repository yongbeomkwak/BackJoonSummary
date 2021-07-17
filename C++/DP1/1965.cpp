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
#define tab " "
#define MOD 9901
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

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        dp[i] = 0;
    }
    //dp[i]= i번째까지 담을 수 있는 최대 수
    dp[1] = 1; // dp[1]은 항상 1 , 1번째 까지 담을 수 있는 최대 수는 1개

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i; j++) // 1부터 i까지 확인
        {
            if (arr[j] < arr[i]) //j앞 박스 , i가 뒷박스 ,담을 수 있는지 확인
            {
                dp[i] = max(dp[i], dp[j]); //각 케이스 마다 최대값
            }
        }
        dp[i]++; // 담았음 증가 (자기 자신을 다음)
        ans = max(ans, dp[i]);
    }
    cout << ans;
}
