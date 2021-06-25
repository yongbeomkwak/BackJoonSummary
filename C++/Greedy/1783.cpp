
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

int min(int &a, int &b)
{
    return a < b ? a : b;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M = 0;
    int answer = 1;
    cin >> N >> M;
    if (N == 1)
    {
        cout << answer;
    }
    else if (N == 2) // 위 아래(1칸 씩) 2,3 번 가능
    {
        answer = min(4, (M + 1) / 2); //세로가 2면 1,4 번 이동 사용 불가 그러므로 최대가 4   ,최대칸= 이동 횟수 +1(첫 칸)
        cout << answer;
    }
    else if (N >= 3) // 1~4 움직임 모두 가능
    {
        if (M <= 6)
        {
            answer = min(4, M); //가로 길이(6) 아래는 4개의 이동 모두 못쓰고 6부터 4개 이동 사용 가능  그러므로 최대가 4개
        }
        else
        {
            answer = M - 2; //  오른쪽으로 2칸 씩 이동 하는 1,4번 이동 한번 씩 총  2번 +
                            //  오른쪽으로 1칸 씩 이동 하는 2,3번  M-5 번 (왜 -5냐 ,처음 위치 -1,위에서 오른쪽  2칸 씩 2번, -4)  그러면 1번 씩 이동 할 수 있는 나머지 칸은 M-5
                            //  촤대칸은 이동 +1 , 첫 출발지도 포함 되므로, 2+M-5+1= M+2
        }
        cout << answer;
    }
}
