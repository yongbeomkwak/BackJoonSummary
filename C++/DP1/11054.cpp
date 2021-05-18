#include <iostream>

#define LMIT 1000
int dp[LMIT];
int in_list[LMIT];
using namespace std;

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &in_list[i]);
    }

    int increase[LMIT];
    int decrease[LMIT];

    for (int i = 1; i <= n; i++)
    {
        increase[i] = 1;
        decrease[i] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (in_list[i] > in_list[j])
            {
                increase[i] = max(increase[i], increase[j] + 1);
            }
        }
    }

    for (int i = n; i >= 1; i--)
    {
        for (int j = n; j > i; j--)
        {
            if (in_list[i] > in_list[j])
            {
                decrease[i] = max(decrease[i], decrease[j] + 1);
            }
        }
    }

    int max_val = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = increase[i] + decrease[i] - 1;
        if (max_val < dp[i])
        {
            max_val = dp[i];
        }
    }
    printf("%d", max_val);
}