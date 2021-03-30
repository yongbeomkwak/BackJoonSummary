#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;
int main()
{
    int tc = 0;
    int cnt = 0;

    scanf("%d", &tc);

    for (int i = 0; i < tc; i++)
    {
        bool primeFlag = true;
        int N = 0;
        scanf("%d", &N);
        if (N != 1) // 1은 소수가 아니기 때문에
        {

            for (int i = 2; i <= N; i++) //2부터 들어온 변수까지 반복
            {

                if ((N % i == 0) && (i != N)) //만약 나눠 떨어졌는데 그게 자기 자신이 아닐 경우
                {
                    primeFlag = false; //false
                    break;
                }
            }
        }

        else //1은 소수아님
        {
            primeFlag = false;
        }
        if (primeFlag)
        {
            cnt++;
        }
    }
    printf("%d", cnt);
}