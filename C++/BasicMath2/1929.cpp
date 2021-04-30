#include <iostream>
#include <cstdio>
#include <array>
#include <algorithm>
using namespace std;
#define MAX 1000001
int main()
{
    int M = 0;
    int N = 0;
    array<bool, MAX> primeArray; // 1~1000000  사용
    primeArray.fill(true);       //초기값 true로
    primeArray[0] = false;       // 0 과 1은 무조건 소수가 아니므로
    primeArray[1] = false;
    scanf("%d %d", &M, &N);

    //에라토스테네스의 체
    for (int i = 2; i <= MAX; i++) // 반복문을 sqrt(i) 번 반복하기위해 i*i
    {
        if (primeArray[i]) //만약 true 일 경우
        {
            for (int j = 2 * i; j <= MAX; j += i) // 즉 i=2 이면(2는 소수) 4부터 시작하기 위해 j=i*i그 배수 관계(j+=i)는 모두 false로 만듬`
            {
                if (primeArray[j] == false)
                {
                    continue;
                }
                primeArray[j] = false;
            }
        }
    }

    for (int i = M; i <= N; i++) // 주어진 구간에서 소수 출력하기
    {
        if (primeArray[i]) //true 여야 출력
        {
            printf("%d\n", i);
        }
    }
}