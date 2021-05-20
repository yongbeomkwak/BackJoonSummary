#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int dp[1001][1001];
string a;
string b;
int max(int a, int b) { return a > b ? a : b; }
int main()
{
    cin >> a >> b;

    for (int i = 1; i <= a.size(); i++)
    {
        for (int j = 1; j <= b.size(); j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[a.size()][b.size()];
}