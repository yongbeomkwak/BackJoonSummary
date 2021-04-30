#include <iostream>
#include <cstdio>
#include <math.h>
#include <string>
using namespace std;

int main()
{
    unsigned int k, n, h, w, yy, xx = 0;
    scanf("%d", &k);            // 입력할 횟수
    for (int i = 0; i < k; i++) //입력한 횟수대로 반복
    {
        scanf("%d %d %d", &h, &w, &n); // 호텔의 높이 너비 ,손님의 순서 입력
        //YYXX 호실
        // YY는 층 XX는 엘리베이터로 부터 거리
        // 낮은 층을 선호
        yy = n % h;  //YY는 층 은 손님의 순서를 높이로 나눈 나머지
        xx = n / h;  // 거리는 몫에 해당
        if (yy == 0) // 만약 나머지가 없다면 xx가 무조건 가장 높은 층에 해당
        {
            if (xx <= 9) // 만약 거리 호실이 9보다 작거나 같으면  09 식으로 되야하므로
            {
                printf("%d0%d\n", h, xx); // 0을 붙여줌
            }
            else
            {
                printf("%d%d\n", h, xx); //거리가 9보다 높으면 두자리니 0 붙일 필요 없
            }
        }
        else //나머지가 0이 아니면 최고층은 아니란 소리
        {
            if (xx < 9) // 똑같이 xx 가  9보다 작으면  0이 붙음 왜 여기는 같은 연산이 없냐면 출력시 xx가 아닌 xx+1을 해주기 때문
            {

                printf("%d0%d\n", yy, xx + 1); // YYXX 꼴인데 여기서 나머지가 0이아니므로 xx는 1이 더해짐
            }
            else
            {
                printf("%d%d\n", yy, xx + 1);
            }
        }
    }
}
