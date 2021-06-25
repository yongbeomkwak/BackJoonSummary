#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, L = 0;
    int leak[10001];
    int answer = 1; //일단 무조건 한개는 필요
    cin >> N >> L;
    //같은 차이 만큼
    //   1(0.5~1.5) 이런식으로
    for (int i = 0; i < N; i++)
    {
        cin >> leak[i];
    }
    sort(leak, leak + N); //오름 차순 정렬 후
    int left = leak[0];   //왼쪽 구멍 위치
    for (int i = 1; i < N; i++)
    {
        int right = leak[i];      //오른 쪽 구멍 위치
        if (right - left > L - 1) // 두 구멍 위치의 차이가 테이프 길이 -1(미리 테이프 길이 에서 (왼쪽 0.5 오른쪽 0.5 사용) 크다는 것은 테이프 한개로는 안된다는 뜻
        {
            left = right; //현재 오른 쪽이 다음 반복의 완쪽이 됨
            answer++;     //테이프 개수 증가
        }
    }

    cout << answer;
}
