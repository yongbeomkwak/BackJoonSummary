#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 31
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
int N[MAX], M[MAX];
int n, T, m;
unsigned long long dp[MAX][MAX];

int main()
{

    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    for (int i = 1; i <= 30; i++) // n=1이고 m=i일 때
    {
        dp[i][i] = 1;
        dp[1][i] = i; //nCr = mCn => dp[n][m]
    }
    /*
     그렇다면 dp[2][4]는 어떻게 될까?
2개의 점에서 가장 위 점이 4개중 가장 위 점으로 간다면
남은 한 점에서 갈 수 있는 경우의 수는 dp[1][3]과 같아진다.
그럼 가장 위의 점이 위에서 2번째 점으로 간다면 dp[1][2]와 같다.
마지막으로 위에서 3번째 점으로 간다면 dp[1][1]과 같다.
dp[i][j] = dp[i-1][j-1] + dp[i-1][j-2] + ... + dp[i-1][i-1]
     */
    for (int i = 2; i <= MAX - 1; i++)
    {
        for (int j = 2; j <= MAX - 1; j++)
        {
            if (i < j) //   mCn jCi=(j-1Ci-1)+  (j-1Ci)   3C2=2C1+ 2C2 => 3= 1+2
            {
                dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
            }
        }
    }

    for (int i = 1; i <= T; i++)
    {
        cin >> n >> m;
        cout << dp[n][m] << "\n";
    }
}
