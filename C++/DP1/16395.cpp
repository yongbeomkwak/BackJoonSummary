#include <bits/stdc++.h>

using namespace std;

#define MAX 31
int n, k;
int DP[MAX][MAX];
int main()
{
    for (int i = 1; i < MAX; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (j == i || j == i)
            {
                DP[i][j] = 1;
                continue;
            }
            DP[i][j] = DP[i - 1][j - 1] + DP[i - 1][j];
        }
    }

    cin >> n >> k;
    cout << DP[n][k];
}
