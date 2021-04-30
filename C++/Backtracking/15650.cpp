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
    for (int i = a; i <= N; i++)
    // 1 2 3===1 3 2 ===2 1  3=== 2 3 1 === 3 1 2===3 2 1이 모두 같아
    // 1 2 3 만 출력하고 다른 조합은 출력하지 않기 위해서는
    // 다음 값은 항상 이전 값보다  커야 한다 1<2 ,2 < 3 이렇게
    // 구현하기 위해서는 재귀호출 시 마다 반복문 시작을 증가시켜(a) 작은 값은 보지 않는다
    //그렇기 때문에 함수 매개변수에는 현재 가르키는 값과 갖고 있는 개수 즉, 매개변수가 2개 필요함
    {
        if (!isUsed[i])
        {
            isUsed[i] = 1;
            arr[b] = i;
            back(i + 1, b + 1); // 첫번째 값:(a==1) -> 다은은 a==2, 즉 i 반복문 시작이 점점 커져서 작은 것은 무시한다
            isUsed[i] = 0;
        }
    }
}

int main()
{
    scanf("%d %d", &N, &M);

    back(1, 0); // 1부터시작 ,현재 0개를 갖고있음
}