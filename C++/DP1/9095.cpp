#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 500001
typedef pair<int, int> pai;
typedef vector<int>::iterator iter;

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
int T;
int memo[11];

int DP(int n)
{
    if (n <= 3)
    {
        return memo[n];
    }
    else
    {
        for (int i = 4; i <= n; i++)
        {
            memo[i] = (memo[i - 1] + memo[i - 2] + memo[i - 3]);
        }
        return memo[n];
    }
}

int main()
{

    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    memo[0] = 0;
    memo[1] = 1;
    memo[2] = 2;
    memo[3] = 4;
    for (int i = 0; i < T; i++)
    {
        int N = 0;
        cin >> N;
        cout << DP(N) << "\n";
    }
}
