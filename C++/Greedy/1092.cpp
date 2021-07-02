#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 500001
typedef pair<int, int> pai;
typedef vector<int>::iterator iter;

int max(const int &a, const int &b)
{
    return a > b ? a : b;
}
int min(const int &a, const int &b)
{
    return a < b ? a : b;
}

bool comp(const int &a, const int &b)
{
    return a > b;
}
int N, M;
int C[51];
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> C[i];
    }
    cin >> M;
    vector<int> Box(M);
    sort(C, C + N, comp); //크레인 무게 내림차순
    for (int i = 0; i < M; i++)
    {
        cin >> Box[i];
    }
    sort(Box.begin(), Box.end(), comp); //Box 무게 내림차순
    while (!Box.empty())                // 비어있을 때 까지 돌림
    {
        if (C[0] < Box.front()) //만약 가장 앞에(가장 무거운) 박스가, 크레인 중 가장 무게를 많이 들어 올릴 수 있는 크레인의 용량 초가면 , -1 while 종료
        {
            ans = -1;
            break;
        }
        else
        {
            for (int i = 0; i < N; i++) // 전체 크레인 돌기
            {
                for (iter it = Box.begin(); it != Box.end(); it++)
                {
                    if (C[i] >= *it) //만약 현제 가르키는 크레인 용량이 현재 가리키는 박스무게 보다 크거나 같으면 옮길 수 있음
                    {
                        Box.erase(it); // 박스 옮김
                        break;         // 종료
                    }
                }

                if (i == N - 1) //만약 마지막 크레인 까지 사용 했다면 , 옮긴 횟수 한번 증가
                {
                    ans++;
                }
            }
        }
    }
    cout << ans;
}
