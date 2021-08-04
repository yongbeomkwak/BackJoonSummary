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
#define MAX 81
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
ull dp[MAX];
ull side_length[MAX];

int chartoi(const char &a)
{
    return (a - '0');
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    side_length[1] = 1;
    side_length[2] = 1;
    for (int i = 3; i < MAX; i++)
    {
        side_length[i] = side_length[i - 1] + side_length[i - 2];
    }
    dp[1] = 4;
    for (int i = 2; i < MAX; i++)
    {
        dp[i] = (side_length[i] + side_length[i - 1]) * 2 + side_length[i] * 2;
    }

    cin >> n;
    cout << dp[n];
}
