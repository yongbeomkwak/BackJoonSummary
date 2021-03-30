#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;
int main()
{
    int M = 0; //M~N
    int N = 0;
    int min = 0;          //최솟값
    int sum = 0;          //합
    bool min_flag = true; //최솟 값 플래그

    scanf("%d %d", &M, &N);

    for (int i = M; i <= N; i++)
    {
        bool prime_flag = true;
        if (i == 1) //만약 i 가 1이면 소수가 아니기 때문에  다음 반복으로
        {
            continue;
        }
        else
        {
            for (int j = 2; j <= i; j++) // j=2 부터 i 까지
            {
                if ((i % j == 0) && (j != i)) //나눴을 때 나머지가 자기 자신과 같지 않으면 소수 아님
                {
                    prime_flag = false; //플래그 false
                    break;
                }
            }
        }

        if (min_flag && prime_flag) // 최초 플래그 와 소수플래그 모두 true면
        {
            min = i;          // 쵯소값
            sum += i;         // 합
            min_flag = false; //최초 플래그 off
        }
        else if (!min_flag && prime_flag) //최초값은 아니지만 소수플래그 일 경우
        {
            sum += i; //합
        }
    }
    if (min == 0 && sum == 0) //만약 모두 초기값에서 변화가 없을 때
    {
        printf("-1"); //-1
    }
    else //아니면 계산 값 출력
    {
        printf("%d\n%d", sum, min);
    }
}