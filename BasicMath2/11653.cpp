#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main()
{
    int N = 0;
    scanf("%d", &N);
    while (N != 1) // 입려된 수가 1이 될 때까지
    {
        int k = 2; // 2로 나누기 시작함
        while (1)  //if조건안에 break를 만나기전 까지 계속
        {
            if (N % k == 0) //만약 나눠지면
            {
                N /= k; //N을 몫으로 다시 값을 넣어주고
                printf("%d\n", k);
                break;
            }
            else //나눠지지 않으면 다음수로 나누기 위해 k를 증가
            {
                k++;
            }
        }
    }
}