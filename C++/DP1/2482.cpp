#include <bits/stdc++.h>

using namespace std;

#define MAX 1001
#define MOD 1000000003
int n, k;
int DP[MAX][MAX];
int main()
{

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        DP[i][0] = 1; // i개 색깔중 0개를 선택할 경우의 수 1개
        DP[i][1] = i; // i개 색깔중 1개를 선택할 경우의 수 i개
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= k; j++)
        {
            DP[i][j] = (DP[i - 2][j - 1] + DP[i - 1][j]) % MOD;
            //(이웃하는 한개를 선택하지 않고)i개 중 j개를 선택할 경우의 수
            // i-2개중 j-1개를 선택하는 경우의 수 (선택할께 1개 남음,그게 j번째 색)
            // i-1개중 j개를 선택하는 경우의 수 (선택할께 없음)
            //의 합 과 같다
        }
    }
    cout << (DP[n - 1][k] + DP[n - 3][k - 1]) % MOD;

    //원형이기 때문에 마지막 색과 첫번째 색역시 이웃이므로 예외처리
    //그러므로 n-1개 중 k를 선택한 경우와 n-3개중 k-1를 선택한 경우의 합이 된다.
}
