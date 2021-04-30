#include <iostream>
#include <cstdio>
#include <algorithm> //max_element를 위한
using namespace std;

int *countingSort(int arr[], const int &n)
{
    int *result = new int[n];             // 결과 배열 생성
    int max = *max_element(arr, arr + n); // 최댓값 찾기(count 배열의 길이에 사용)
    int length = max + 1;
    int *count = new int[length];   //0부터 max값 까지 인덱스로 매치 시키기 위해 길이를 +1
    fill(count, count + length, 0); //모든 값을 0으로 초기화
    for (int i = 0; i < n; i++)
    {
        //arr[i]=3이면 count[3]이 +1
        count[arr[i]] += 1; //arr 배열 각 원소 값에 해당하는 인덱스의 count 값을 올려준다
    }
    // 만약 count=0 1 3 3 4
    for (int i = 0; i <= max; i++)
    {
        count[i + 1] += count[i]; //누접합
    }
    //count = 0 1 4 7 11

    //input:[3,4,0,1,2,4,2,4] 누접합:[1,2,4,5,8]
    //arr[1]=3 -> count[3]=5
    //count[3]=5은 3이라는 숫자위치의 누적합 0~3 까지 합한 위치가가 5라는 소리
    //5번째는 인덱스 상 4에 해당됨, 그러므로 결과배열에서는 -1을 해줘야함
    //result[count[arr[i]]-1]=arr[i]
    for (int i = 0; i < n; i++)
    {

        result[count[arr[i]] - 1] = arr[i]; //결과 넣어주기
        count[arr[i]]--;                    //해당 위치 누적합 감소
    }

    return result;
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

    arr = countingSort(arr, N);

    for (int i = 0; i < N; i++)
    {
        printf("%d\n", arr[i]);
    }
}
