#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
int main()
{
    int n, ans;
    scanf("%d", &n);

    if (n % 5 == 0) // 5로 나누어 떨어지면 전부 5로
        ans = n / 5;
    else if (n % 5 == 1)            // 1이 남는 다는 뜻은 한번 덜 나누면 6, 즉 6이 남는 상황
        ans = (n / 5) + 1;          // 6 -> 3 ->n/5 3 ->1
    else if (n % 5 == 2 && n >= 12) // 12가 남는 꼴
        ans = (n / 5) + 2;          //3 3 3 3 -> 3 3 -> n/5 , 3 3->2
    else if (n % 5 == 3)            // 3이 남는 꼴.
        ans = (n / 5) + 1;          //3 -> 1
    else if (n % 5 == 4 && n >= 9)  // 9가 남는 꼴
        ans = (n / 5) + 2;          //3 3 3  3->n/5  ,3 3 ->2
    else
        ans = -1;

    printf("%d", ans);
}
