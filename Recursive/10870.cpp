#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int fibo(const int &num)
{
    if (num == 0)
    {
        return 0;
    }
    else if (num > 2)
    {
        return fibo(num - 1) + fibo(num - 2);
    }
    else
    {
        return 1;
    }
}
int main()
{
    int n = 0;
    scanf("%d", &n);
    printf("%d", fibo(n));
}