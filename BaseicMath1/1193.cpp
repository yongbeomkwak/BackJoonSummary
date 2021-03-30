#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
int main()
{
    int unsigned curr = 1; //현재 가르키고 있는 값

    unsigned int x = 0; // 입력 값
    scanf("%d", &x);
    int r = 1;        // 현재 row
    int c = 1;        // 현재 col
    while (curr != x) //입력받은 값과 현재가르키는 값이 같을경우 종료
    {

        if (((r + c) % 2) == 0) //만약  row+c 가 짝수일 경우 우측상향 또는 우측
        {
            if (r == 1) //그리고 그 row가 1일 경우 우측 이므로 column +1
            {
                c++;
            }
            else // 아닐경우 우측 상향  row -1 col +1
            {
                r--;
                c++;
            }
        }
        else //홀수 일경우 좌측 하향 또는 하향
        {
            if (c == 1) //하향 row +1
            {
                r++;
            }
            else //좌측 하향 col -1 ,row +1
            {
                r++;
                c--;
            }
        }
        curr++; // column과 row 이동 후 현재 가르키는 값 증가
    }
    printf("%d/%d", r, c); //결과 출력
}