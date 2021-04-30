#include <iostream>
#include <cstdio>

void solve(int const &x, int const &y, int const &n, char **const star)
{
    //현재 시작할 x,y와 현재 무슨 형태인지 n,사용할 2차배열
    if (n == 3)
    { //n==3이 리턴
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (i == 1 && j == 1)
                {                             //가운데 값을 비우기 위한 중간값인 1
                    star[x + i][y + j] = ' '; //비워준다
                    continue;
                }
                star[x + i][y + j] = '*'; //아니면 채워준다
            }
        }
        return;
    }
    int m = n / 3;
    //작은 사각형으로 하나씩 검사하기 위한 반복문
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == 1 && j == 1)
            { //중간값을 빼주기 위함 (9 입력 시 (3,3)~(5,5)) 빼주기 위함
                continue;
            }
            solve(x + i * m, y + j * m, m, star); //작은 사각형으로 분산하여 검사
        }
    }
    /* N=9 일 때
N: 9 x: 0 ,y: 0
### 작은 사각형으로 분리 ###
N: 3 x: 0 ,y: 0 (0~2,0~2 정사각형 보고)
N: 3 x: 0 ,y: 3 (0~2,3~5 정사각형 보고 )
N: 3 x: 0 ,y: 6 (0~2,6~8 정사각형 보고 )  
N: 3 x: 3 ,y: 0 
############### 보면 3,3이 없음 solve 재귀 위의 if 문에서 걸러짐 
N: 3 x: 3 ,y: 6
N: 3 x: 6 ,y: 0
N: 3 x: 6 ,y: 3
N: 3 x: 6 ,y: 6
*/
}

int main()
{
    int N = 0;
    scanf("%d", &N);
    char **str = new char *[N + 1]; //2차원 배열

    for (int i = 0; i < N; i++)
    {
        str[i] = new char[N + 1];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {

            str[i][j] = ' ';
        }
    }
    // 초기값은 비어있게 설정
    solve(0, 0, N, str);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%c", str[i][j]);
        }
        printf("\n");
    }
}