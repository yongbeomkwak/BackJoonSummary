#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int turret(const int arr[])
{
    int x1 = arr[0];
    int y1 = arr[1];
    int r1 = arr[2];
    int x2 = arr[3];
    int y2 = arr[4];
    int r2 = arr[5];
    int dx = x2 - x1;
    int dy = y2 - y1;
    // 중요한 것은 sqrt를 쓰면 오류가 많이 발생하기 때문에 제곱 상태를 많이 이용했다
    //a^2=b^2+c^2  상태
    double d = pow(dx, 2) + pow(dy, 2); //루트를 씌우지않음
    double r_max = r1 + r2;
    double r_min = abs(r1 - r2);          //차이기 때문에
    if (x1 == x2 && y1 == y2 && r1 == r2) //완저히 겹칠 경우
    {
        return -1;
    }
    else if (d == pow(r_max, 2) || d == pow(r_min, 2)) //외접 또는 내접일 경우
    {
        return 1;
    }
    else if (d > pow(r_max, 2) || pow(r_min, 2) > d)
    {
        //내부에 있지만 접하지 않거나, 외부에 멀리 떨어질 때
        return 0;
    }
    else // 모두 포함안되면 두점에서 만날때
    {
        return 2;
    }
}
int main()
{
    int tc = 0;
    scanf("%d", &tc);

    for (int i = 0; i < tc; i++)
    {
        int arr[6] = {0};
        scanf("%d %d %d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4], &arr[5]);
        printf("%d\n", turret(arr));
    }
}