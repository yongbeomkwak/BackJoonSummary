#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 2001
#define endl "\n"
#define tab " "
#define MOD 1000000009
#define INF 987654321
typedef pair<int, int> pai;
typedef vector<int>::iterator iter;
typedef unsigned long long ull;

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

int n;
typedef struct _CLIP
{
    int screen, clip, time; //화면,복사한 개수,시간
} Clip;
bool dp[MAX][MAX]; //dp[i][x] = 현재 화면에 i개 , 클립보드에 x개 복사 상태

int BFS()
{
    queue<Clip> q;
    Clip init_c = {1, 0, 0};
    q.push(init_c);
    dp[1][0] = true; //초기 화면에 한개 보이고 복사한 것 없음

    while (!q.empty())
    {
        Clip c;
        int screen = q.front().screen;
        int clip = q.front().clip;
        int time = q.front().time;
        q.pop();
        if (screen == n) // 현재 화면에 있는 개수와 원하는 개수가 같을 경우 리턴
        {
            return time;
        }
        if (screen > 0 && screen < MAX) //화면에 있는 그림을 클립보드에 복사 하거나(1번 조건),현재 상태에서 1개를 제거하기 위해서는(3번 조건)   screen에 1개 이상 있어야함
        {
            if (dp[screen][screen] == false) //해당 스크린에 있는 그림을 클립보드에 복사 하지 않은 상태라면
            {
                dp[screen][screen] = true;
                c.clip = screen;   //클립보드에 화면에 있는 것 복사
                c.time = time + 1; //시간증가
                c.screen = screen;
                q.push(c);
            }
            if (dp[screen - 1][clip] == false) //한 개 제거한 상태가 존재 하지 않았던 상태라면
            {
                dp[screen - 1][clip] = true;
                c.screen = screen - 1; //화면에서 하나 제거
                c.time = time + 1;     // 시간증가
                c.clip = clip;
                q.push(c);
            }
            //클립보드에 있는거 붙여 넣기 위해서는
        }
        if (clip > 0 && clip + screen < MAX) // clip에 있는거 붙여넣기 , 조건은 clip에  0보다 커야하고 clip+screen이 MAX보다 작아야함
        {
            if (dp[screen + clip][clip] == false)
            {
                dp[screen + clip][clip] = true;
                c.screen = screen + clip; //그림 증가
                c.time = time + 1;        //시간 증가
                c.clip = clip;
                q.push(c);
            }
        }
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    cout << BFS();
}
