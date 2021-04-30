#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;
bool comp(int a, int b) //오름차순 정렬 비교 함수
{
    if (a < b)
    {
        return true;
    }
    return false;
}

int main()
{
    int N = 0;          // 카드 갯수
    int total = 0;      // 현재 합
    int prev_total = 0; // 이전 합
    int in = 0;         //백터에 저장하기 위한 임시 변수
    int M = 0;          // 목표값
    vector<int> v1;
    using namespace std;
    scanf("%d %d", &N, &M);     // 카드 갯수와 목표값 입력 받음
    for (int i = 0; i < N; i++) // 백터에 값을 집어 넣음
    {
        scanf("%d", &in);
        v1.push_back(in);
    }
    vector<int>::iterator begin = v1.begin();
    sort(begin, begin + N, comp); //comp 함수를 이용하여 오름차순

    //모든 경우를 검사하기 위해 카드 세장의  합이니깐 roop가 3개
    for (int i = N - 1; i >= 2; i--) // 가장 큰 값
    {
        for (int j = i - 1; j >= 1; j--) // 중간 값
        {
            total = 0;                       //총합 초기화
            for (int k = j - 1; k >= 0; k--) //가장 작은 값
            {

                if (v1[i] + v1[j] + v1[k] == M) // 3장의 카드가 모표 값과 같으면
                {
                    total = M; // 총 합값 변경
                    break;     // 반복문 종료
                }
                else if (v1[i] + v1[j] + v1[k] < M)
                {
                    total = v1[i] + v1[j] + v1[k];
                    if (prev_total < total)
                    {
                        prev_total = total;
                    }
                }
            }
            if (total == M) //두번 째 반복문 종료
            {
                break;
            }
        }
        if (total == M) //3번 째 반복문 종료 
        {

            break;
        }
    }
    if (prev_total > total) // 끝까지 조사했을 때 전 값과 현재 값 비교 했을 때 이전 값이 클 때 total 변경
    {
        total = prev_total;
    }
    printf("%d", total); //출력
}