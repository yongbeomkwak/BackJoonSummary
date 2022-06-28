#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    char A[51][51];
    char B[51][51];
    bool C[51][51];
    int N = 0;
    int M = 0;
    int answer = 0;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> A[i][j]; //A배열 입력 받기
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> B[i][j];         // B입력 받기
            if (A[i][j] != B[i][j]) //만약 A와 다를 시
            {
                C[i][j] = false; //flag 배열에 false 삽입
            }
            else
            {
                C[i][j] = true; //아니면 true
            }
        }
    }
    if (N < 3 || M < 3) //만약 하나라도 3보다 작을 경우  배열 reverse가 안됨
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (!C[i][j]) //같으면 상관없지만 한번이라도 false 나오면 reverse가 안되므로 같아질 수 없음
                {
                    answer = -1; //정답 -1
                }
            }
        }
        cout << answer; //출력
    }
    else
    {
        for (int i = 0; i < N - 2; i++) // N=3 일경우 , i=0 , N=4일 경우 i=0,1    ...
        {
            for (int j = 0; j < M - 2; j++)
            {
                if (!C[i][j]) //만약 해당 위치가 false이면 reverse 해야함
                {
                    answer++;                       //증가
                    for (int p = i; p < i + 3; p++) //해당 위치로  부터 3칸 확인
                    {
                        for (int q = j; q < j + 3; q++)
                        {
                            C[p][q] = !C[p][q]; // 뒤집기
                        }
                    }
                }
            }
        }
        for (int i = 0; i < N; i++) //최종 확인
        {
            for (int j = 0; j < M; j++)
            {
                if (!C[i][j]) //모두 뒤집은 후에도 false가 나오면 같아 질 수 없음
                {
                    answer = -1; //answer초기화
                    break;
                }
            }
        }
        cout << answer; // 최종 출력
    }
}
