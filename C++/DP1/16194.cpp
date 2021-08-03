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

int n;
int dp[MAX];
int card[MAX];
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> card[i];
        dp[i] = card[i];            //일단 초기화는 해당 카드 갯수에 딱 맞는 값을 넣고
        for (int j = 1; j < i; j++) //LIS 느낌 처럼
        {
            dp[i] = min(dp[i], dp[i - j] + dp[j]); // i=3 일 때 ,  3-1  +1(2개짜리와 1개), 3-2 +2(1개 짜리와 2개) ,
            //경우 비교 (3개 짜리는 이미 위에서 넣었음 )
        }
    }
    cout << dp[n] << endl;
}
