#include <cstdio>
#include <cmath>
#define PI 3.14159265358979
int main()
{
    double r = 0;
    scanf("%lf", &r);
    printf("%.6lf\n", r * r * PI);
    printf("%.6lf", 2 * r * r); //택시 거리의 원은 원이아닌 정사각형이 정삭가형의 한변의 길이는 ,아르키메데스의 원 반지름에  루트 2배임
}