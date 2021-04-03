#include <iostream>
#include <cstdio>
using namespace std;

bool comp(const int &w1, const int &h1, const int &w2, const int &h2)
{
    if (w2 > w1 && h2 > h1) // 몸무게와 키가 모두 커야 true
    {
        return true;
    }
    return false;
}
int main()
{
    int tc = 0;
    scanf("%d", &tc);
    int *w = new int[tc];      //무게를  저장할 배열
    int *h = new int[tc];      // 키를 저장할 배열
    int *result = new int[tc]; //결과를 저장할 배열

    for (int i = 0; i < tc; i++)
    {
        scanf("%d %d", &w[i], &h[i]); //입렫 받음
    }
    for (int i = 0; i < tc; i++)
    {
        int rate = 1; //초반 등수는 1
        for (int j = 0; j < tc; j++)
        {
            if (i == j) //같다는건 같은사람 넘어가
            {
                continue;
            }
            else
            {
                if (comp(w[i], h[i], w[j], h[j])) // 비교후 투르면
                {
                    rate++; //등수 증가
                }
            }
        }
        result[i] = rate; //결과에 등수 저장
    }
    for (int i = 0; i < tc; i++)
    {
        printf("%d ", result[i]); //등수 출력
    }
}