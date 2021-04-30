#include <iostream>
#include <cstdio>
using namespace std;

int cal(const unsigned int &a, const unsigned int &b, const unsigned int &c)
{
    if (b >= c)
    {
        return -1;
    }
    else
    {
        return (a / (c - b)) + 1;
    }
}

int main()
{
    unsigned int a, b, c = 0;
    scanf("%d %d %d", &a, &b, &c);
    printf("%d", cal(a, b, c));
}