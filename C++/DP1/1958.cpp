#include <bits/stdc++.h>

using namespace std;

#define MAX 101

int dp[MAX][MAX][MAX];

int gmax(const int a, const int b, const int c)
{
    return max(a, max(b, c));
}

int main()
{
    string a, b, c;

    cin >> a;
    cin >> b;
    cin >> c;
    a = ' ' + a;
    b = ' ' + b;
    c = ' ' + c;
    //여백을 더 해준다. 인덱스 연산을 편하게 하기위해
    const int len1 = a.length() - 1; //공백을 빼야하므로
    const int len2 = b.length() - 1; //
    const int len3 = c.length() - 1;
    for (int i = 1; i < a.length(); i++)
    {
        for (int j = 1; j < b.length(); j++)
        {
            for (int k = 1; k < c.length(); k++)
            {

                if (a[i] == b[j] && b[j] == c[k]) // 세개 모두 같으면
                {
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1; //이전 값에 길이를 하나 더 더해준다.
                    continue;
                }
                dp[i][j][k] = gmax(dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]); // a의 이전,b의 이전,c의 이전 중 최댓값으로 채움
            }
        }
    }

    cout << dp[len1][len2][len3];
}