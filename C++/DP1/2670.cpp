#include <bits/stdc++.h>

using namespace std;

#define MAX 10001

int n;

double arr[MAX];
double dp[MAX];

int main()
{

    cin >> n;
    cout << fixed;
    cout.precision(3);

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    dp[0] = arr[0];
    double ret = 0.0;
    for (int i = 1; i < n; i++)
    {
        dp[i] = max(arr[i], arr[i] * dp[i - 1]);
        ret = max(dp[i], ret);
    }
    cout << ret;
}
