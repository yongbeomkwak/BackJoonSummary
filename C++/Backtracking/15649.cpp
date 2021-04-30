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
        if (!isUsed[i]) //i번째 인덱스 가 아직 사용중이 아니면
        {
            isUsed[i] = 1; //사용중으로 바꾼 후
            arr[a] = i;    //현재 가르키고 있는 자리에 i를 넣어줌(arr 배열은 (0~(M-1)) 까지만 채워짐
            //ex   N=4, M=2
            //a=0, arr[0] =1  -> a=1, 1(i) 은 사용 중,  arr[(1)]= 2 .. 3.. 4 이렇게 i로 들어감
            back(a + 1);   // 가르킬 숫자 개수를 증가
            isUsed[i] = 0; // 사용중 해제 (다음 순환 때 그 전 값을 참고 할수 있게 )
                           // ex) 1 2 3 4 , 1 2 4 3 처럼 3 4 쓰고 3을 사용 해제 해야 4 3이 될 수 있음
        }
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