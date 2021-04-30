#include <iostream>
#include <cstdio>

using namespace std;
void mergeSort(int[], const int &); // 처음에 시작될 함수
void mSort(int[], int[], int, int); //분할 작업
void merge(int[], int[], int, int, int); //병합 작업

void mergeSort(int arr[], const int &length) //정렬할 배열,길이
{
    int *temp = new int[length];     // 임시 저장 배열
    mSort(arr, temp, 0, length - 1); // 정렬할 배열,임시 배열,시작 인덱스,끝 인덱스
}
void mSort(int arr[], int temp[], int start, int end)
{
    int mid = (start + end) / 2; //중간 값
    if (start < end)             // 최종 비교 대상이 2개가 될 때까지
    {
        mSort(arr, temp, start, mid);      //start 부터 중간 까지
        mSort(arr, temp, mid + 1, end);    //중간 다음부터 끝까지
        merge(arr, temp, start, mid, end); //병합 과정
    }
}
void merge(int arr[], int temp[], int start, int mid, int end)
{ //정렬 시킬 배열,임시 배열,시작점,중간점,끝점
    for (int i = start; i <= end; i++)
    {
        temp[i] = arr[i]; // 필요한 만큼 먼저 복사
    }
    int part1 = start;                   //왼쪽 부분 가르키는 인덱스
    int part2 = mid + 1;                 //오른쪽 부분 가르키는 인덱스
    int index = start;                   //저장할 위치
    while (part1 <= mid && part2 <= end) //왼쪽 오른쪽 모두 끝에 도달할 때까지
    {
        if (temp[part1] <= temp[part2]) //왼쪽 배열이 오른쪽 배열보다 작으면
        {
            arr[index] = temp[part1]; //part1이 작다는 뜻이니 먼저 저장
            part1++;                  //part1을 다음껄로 이동
        }
        else
        {
            arr[index] = temp[part2]; //part2에 해당되는 값을 저장
            part2++;                  //part2 증가
        }
        index++; // 어디를 넣든 저장할 위치는 무조건 증가
    }
    for (int i = 0; i <= mid - part1; i++) //왼쪽 배열은 값이 남아있는데,오른쪽 배열은 비어있을 때
    {                                      //mid-part1 의미는 앞쪽 배열의 끝이 mid이므로 앞쪽 배열의 끝에서 남은 만큼 돌아라
        arr[index + i] = temp[part1 + i];  //남은 완쪽 배열들 넣어줌
    }
    // 뒤쪽 배열은 초반 부터 오른쪽에 즉 뒤쪽에 있으므로 따로 걱정 안해도 됨
}
int main()
{
    int N = 0;
    scanf("%d", &N);
    int *arr = new int[N];
    for (int i = 0; i < N; i++) //입력
    {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, N); //병합 정렬 시작
    for (int i = 0; i < N; i++) //출력
    {
        printf("%d\n", arr[i]);
    }
}
