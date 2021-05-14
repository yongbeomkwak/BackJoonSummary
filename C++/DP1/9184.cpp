#include <iostream>
#include <cstdio>
using namespace std;

#define LMIT 21

int dp[LMIT][LMIT][LMIT];

int w(int a, int b, int c)
{

    if (a <= 0 || b <= 0 || c <= 0)
    {
        return 1;
    }
    if (a > 20 || b > 20 || c > 20)
    {
        return w(20, 20, 20);
    }
    if (dp[a][b][c])
    {
        return dp[a][b][c];
    }
    if (a < b && b < c)
    {
        dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
        return dp[a][b][c];
    }
    dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    return dp[a][b][c];
}

int main()
{

    while (true)
    {
        int a = 0;
        int b = 0;
        int c = 0;
        scanf("%d %d %d", &a, &b, &c);
        if (a == -1 && b == -1 && c == -1)
        {
            break;
        }
        printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
    }
}