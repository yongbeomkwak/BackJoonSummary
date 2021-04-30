#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;

int cal(const unsigned int &a)
{
    int c = 0;
    if (a > 1) // 1이 아니면
    {
        for (int i = 1; i <= a; i++)
        {
            if (((3 * i * i) + (-3 * i) + 1) >= a)
            //(1..7..19..37..61) 이 숫자들이 지나가는 갯수가 바뀌기전의 마지막 숫자이다 그러므로 >=를 사용
            //같이 증가 1+6(0)  1+6(1)  1+6(3)
            // 크게는 등차 수열 같으 느낌이지만 () 안에 숫자가 부분 합으로 바뀜
            //1 3 6 10 - > 1 1+2 1+2+3 1+2+3+4 -> 1+ (n(n-1)/2) 다시 괄호 안을 점화 식으로 넣으면
            // 1+6(n(n-1)/2) -> 3n^2 -3n +1
            //3n^2 -3n +1
            {
                c = i;
                return c;
            }
        }
    }
    return 1;
}

int main()
{
    unsigned int a = 0;
    scanf("%d", &a);
    printf("%d", cal(a));
}