#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
string RC[10001]; //입력
int R, C;
int ans = 0;
int movearr[3][2] = {{-1, 1}, {0, 1}, {1, 1}}; // (-1,1) 우 상향 ,(0,1) 우 , (1,1) 우 하향
/*
1. 파이프라인을 많이 만들기 위해서는 해당 파이프라인이 최대한 원웅이의 빵집 상단에 도달해야합니다.

2. 따라서, DFS 탐색을 오른쪽 상단, 오른쪽, 오른쪽 하단 순으로 탐색합니다.


*/
bool isVisited[10001][501];
int max(int &a, int b)
{
    return a > b ? a : b;
}
bool DFS(int r, int c)
{
    isVisited[r][c] = true;

    if (c == (C - 1))
    {
        return true;
    }

    for (int i = 0; i < 3; i++)
    {
        int nextR = r + movearr[i][0]; //다음 좌표 결정 (상,하)
        int nextC = c + movearr[i][1]; // 다음 좌표 결정 (우)
        if (0 <= nextR && nextR < R && 0 <= nextC && nextC < C)
        {
            if (!isVisited[nextR][nextC] && RC[nextR][nextC] == '.') // 다음 경로에  건물이 없고, 아직 방문하지 않았다면
            {
                if (DFS(nextR, nextC))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;

    for (int i = 0; i < R; i++)
    {
        cin >> RC[i];
    }

    for (int i = 0; i < R; i++)
    {
        ans += DFS(i, 0); //3. 각 높이마다 시작해서 파이프라인을 생성할 수 있는지 확인하고 생성할 수 있으면 결과값에 더해줍니다.
    }
    cout << ans;
}
