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
int N;
int memo[1001];

int DP(int n)
{
    if (n <= 2)
    {
        return memo[n];
    }
    else
    {
        for (int i = 3; i <= n; i++)
        {
            memo[i] = (memo[i - 1] + memo[i - 2]) % 10007;
        }
        return memo[n];
    }
}

int main()
{

    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    memo[0] = 1;
    memo[1] = 1;
    memo[2] = 2;

    cout << DP(N) << "\n";
}
