#include <iostream>
#include <cstdio>
#include <cstdlib>

typedef long long int lli;

int main()
{
    lli S = 0;
    lli sum = 0;
    lli sum2 = 0;
    lli N = 0;
    scanf("%lld", &S);
    if (S == 1)
    {
        printf("1");
    }
    else
    {
        for (int i = 1; i <= S; i++)
        {
            if (sum <= S)
            {
                sum += i;
            }
            if (sum > S) //기준치를 넘었을 때 
            {
                N = i; //그 더한 횟수를 저장 i=가 7이라는 의미는 7번의 덧셈이 있었다는 뜻 
                break;
            }
        }
        printf("%lld\n", N - 1); //그러면 정답은 넘기전의 홧수의 -1 이 된다 
    }
}