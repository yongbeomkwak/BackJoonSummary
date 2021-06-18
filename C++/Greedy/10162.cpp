#include <iostream>
#include <cstdio>

using namespace std;

int min(int a, int b)
{
    return a < b ? a : b;
}
int sum(int a, int b, int c)
{
    return a + b + c;
}
int main()
{
    int T = 0;
    int A = 0;
    int B = 0;
    int C = 0;
    int result = 0;
    scanf("%d", &T);
    if (T % 10 != 0)
    {
        printf("-1");
    }
    else
    {
        while (T != 0)
        {
            if (T >= 300)
            {
                A = T / 300;
                T %= 300;
                result = sum(A, B, C);
            }
            else if (T >= 60)
            {
                B = T / 60;
                T %= 60;
                result = sum(A, B, C);
            }
            else
            {
                C = T / 10;
                T %= 10;
                result = sum(A, B, C);
            }
        }
        printf("%d %d %d", A, B, C);
    }
}