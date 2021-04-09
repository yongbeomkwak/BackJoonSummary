#include <iostream>

#include <cstdio>

using namespace std;
void swap(int *arr, int a, int b) //자리 바꿈 함수
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}
int partition(int *arr, int start, int end) //구간 나누기
{
    int piviot = arr[(start + end) / 2]; //중간값
    while (start <= end)                 // start가 아직 end를 지나치지 않으면 계속
    {
        while (arr[start] < piviot)
            start++; //start가 가르키는 값이 중간값보다 작으면 문제없음 오른쪽으로 이동,같거나 크면 멈춤
        while (arr[end] > piviot)
            end--;        //end가 가르키는 값이 중간값보다 크면 문제없음 왼쪽으로 진행 작거나 같으면 멈춤
        if (start <= end) //위 2 while 멈췄다는 뜻은 바꿀 값을 찼았다는 듯
        {
            swap(arr, start, end); //변경
            start++;               //계속 오른쪽으로 진행
            end--;                 //계속 왼쪽으로 진행 , 그러다 가장 바깥 while조건에 걸리면 종료
        }
    }
    return start; //이후 다음 오른쪽 partition의 시작값을 리턴함
                  // xxxxxxx end start xxxxxxxx  가 됬기 때문에 start가 다음 오른쪽 시작값이 됨
}

void quickSort(int *arr, int start, int end)
{
    int right_start = partition(arr, start, end); //오른쪽 시작값을 partition으로 부터 받은 후
    if (start < right_start - 1)                  //만약 시작값이 오른쪽 시작값의 바로 전 값보다 같거나 작으면 왼쪽에 정렬할 값이 1개 이하라는 뜻 즉 정렬할필요없음
    {
        quickSort(arr, start, right_start - 1); //왼쪽 정렬(시작값,오른쪽시작의 바로 전값이 왼쪽 구역의 끝값이 됨)
    }
    if (right_start < end) //마찬가지로 오른쪽 시작값이 끝값보다 크거나 같으면 오른쪽 부분의 정렬할 갯수가 1개 이하니깐 정렬할 필요 없다
    {
        quickSort(arr, right_start, end);
    }
}
int main()
{
    int N = 0;
    scanf("%d", &N);
    int *arr = new int[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    quickSort(arr, 0, N - 1);
    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
}