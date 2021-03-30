#include <iostream>
#include <cstdio>
#include <array>
#include <algorithm>
using namespace std;
#define MAX 250000
int main()
{

    array<bool, MAX> primeArray; // 1~1000000  사용
    primeArray.fill(true);       //초기값 true로
    primeArray[0] = false;       // 0 과 1은 무조건 소수가 아니므로
    primeArray[1] = false;

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

    while (1)
    {
        int cnt = 0;
        int n = 0;
        scanf("%d", &n);
        if (n == 0)
            break;
        for (int i = n + 1; i <= n * 2; i++)
        {
            if (primeArray[i])
            {
                cnt++;
            }
        }
        printf("%d\n", cnt);
    }
}