#include <iostream>
#include <cstdio>
using namespace std;

int arr[10];
int isUsed[10];
int N, M;
void back(const int &a, const int &b) //현재 가르키는 값,갖고 있는 개수
{
    if (b == M) //갖고 있는 개수가 M가 갖다면 출력이 가능함
    {
        for (int i = 0; i < M; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }
    for (int i = 1; i <= N; i++)
    {

        if (i >= a) //i가 현재 가르키고 있는값(a)보다 클 때 만 다음 단계로 넘어간다
        {
            arr[b] = i;
            back(i, b + 1); 
        }
    }
}

int main()
{
    scanf("%d %d", &N, &M);

    back(1, 0); // 1부터시작 ,현재 0개를 갖고있음
}