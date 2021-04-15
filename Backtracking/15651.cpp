#include <iostream>
#include <cstdio>
using namespace std;

int arr[10];
int isUsed[10];
int N, M;
void back(const int &a) //a는 현재 갖고 있는 사용할 수 있는(가르키고 있는) 숫자의 개수
{
    if (a == M) //a가 출력할 갯수(M아)가 되면
    {
        for (int i = 0; i < M; i++) //해당 순회에 대한 값 출력
        {
            printf("%d ", arr[i]);
        }
        printf("\n"); // 줄바꿈
        return;
    }

    for (int i = 1; i <= N; i++) //1~N까지
    {

        arr[a] = i; //현재 가르키고 있는 자리에 i를 넣어줌(arr 배열은 (0~(M-1)) 까지만 채워짐
        //ex   N=4, M=2
        //a=0, arr[0] =1  -> a=1, 1(i) 은 사용 중,  arr[(1)]= 2 .. 3.. 4 이렇게 i로 들어감
        back(a + 1); // 가르킬 숫자 개수를 증가
    }
}
/*
 M이 한번 출력할 때 개수 이기 때문에 배열은 M번 돌면 됨  
  */
int main()
{
    scanf("%d %d", &N, &M);

    back(0);
}