#include <iostream>
#include <cstdio>
using namespace std;

#define LMIT 101

int main()
{
    int n = 0;
    int tc = 0;
    scanf("%d", &tc);
    for (int j = 0; j < tc; j++)
    {
        long long padovan[LMIT];
        padovan[1] = 1, padovan[2] = 1, padovan[3] = 1;
        scanf("%d", &n);
        for (int i = 4; i <= n; i++)
        {
            padovan[i] = padovan[i - 3] + padovan[i - 2];
        }

        printf("%lld\n", padovan[n]);
    }
}