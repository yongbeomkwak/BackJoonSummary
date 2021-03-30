#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;

int cal(const unsigned int &a, const unsigned int &b, const unsigned int &v)
{
    // a= 한번에 올라가는 거리 ,b= 한번에 미끄러지는 거리, v= 목표 거리
    int av = v / a;                       // 확실히 올라가는 일수
    int result = v - (av * a) + ((av)*b); // 확실히 올라가고 남은 거리, 확실히 올라 갔으니 미끄러지는 일수 만큼 b를 더해줌
    if (v != a)                           //목표 지점과  올라갈 수 있는 거리가 같지 않으경우, 무조건 1 이상
    {
        if (result > a) //만약 남은 거리가  한번에 올라갈 높이보다 클 경우
        {
            while (true)
            {
                if (result > a) //만약 남은 거리가  한번에 올라갈 높이보다 클 경우
                {
                    int avv = result / a;                    //  확실히 올라갈 일 수  한번 더 계산
                    result = result - (avv * a) + (avv * b); //남은거리 변경
                    av += avv;                               // 처음 계산한 확실히 올라간 일수 + 그 후 계산한 확실한 일 수
                }
                else // 여기는 av+avv+....+avv+ 1
                {
                    return av + 1; //다음번 올라가면 끝 그러므로 +1
                }
            }
        }

        else //한번 비교로 한번에 올라갈 거리보다 남은 거리가 작은경우
        {
            return av + 1; //다음번 올라가면 끝 그러므로 +1
        }
    }
    else //올라갈 거리와 목표지점이 값이 같을 경우 오전만에 무조건 올라감
    {
        return 1;
    }
}
int main()
{
    unsigned int a, b, c = 0;
    scanf("%d %d %d", &a, &b, &c);
    printf("%d", cal(a, b, c));
}