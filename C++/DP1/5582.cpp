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
#define MAX 4001
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

char s1[MAX], s2[MAX];
int dp[MAX][MAX];
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s1 >> s2;
    int ans = 0;
    for (int i = 1; i <= strlen(s1); i++)
    {
        for (int j = 1; j <= strlen(s2); j++)
        {
            //현재 값이 i-1 과 j-1 임 , i와 j 가 아님
            if (s1[i - 1] == s2[j - 1]) //현재 값이 같으면, 대각선 값인  [i][j]에 ,현재 값의 +1을 해준다 ,왜 대각선이냐 ? 연속하는 문자열을 봐야 하기 때문에
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                ans = max(ans, dp[i][j]);
            }
        }
    }
    cout << ans << endl;
}
