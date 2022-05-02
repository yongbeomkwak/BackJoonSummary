#include <bits/stdc++.h>

using namespace std;

#define MAX 21

using namespace std;

int L[MAX] = {0,};
int J[MAX] = {0,};
int dp[MAX][101];
int n;
int solve(const int idx, const int life)
{
    if (dp[idx][life])
        return dp[idx][life];
    int &ans = dp[idx][life];
    if (idx == n)
        return 0; // 인원을 초과

    if (life - L[idx] > 0)
        ans = solve(idx + 1, life - L[idx]) + J[idx]; //현재 사람 인사를하고

    int tmp = solve(idx + 1, life); //현재 사람 인사를하지 않고

    ans = max(ans, tmp);

    return ans;
}

int main()
{

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> L[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> J[i];
    }

    cout << solve(0, 100); // 0번째 사람, 라이프 100 부터 시작
}