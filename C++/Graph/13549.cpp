/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define MAX 100001
#define INF 987654321
int _visit[MAX];
int dist[MAX];

int main()
{
    int n, k;
    cin >> n >> k;
    fill(dist, dist + MAX, INF); //무한대로 초기화
    queue<int> q;

    dist[n] = 0;
    q.push(n);

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        if (_visit[now] == 1)
            continue; //만약 이미 방문하면 다시
        if (now == k)
            break;       // k 도착시 종료
        _visit[now] = 1; //방문

        int next = now * 2; //다음 행성지

        if (next <= MAX - 1 && dist[next] > dist[now]) // 범위에 있으며 다음 목적지 거리가 현재거리보다 크면
        {
            q.push(next);           //큐 삽입
            dist[next] = dist[now]; //변경
        }
        next = now - 1;                              //다음 행성지
        if (next >= 0 && dist[next] > dist[now] + 1) //범위에 있으며 다음 목적지 거리가 현재거리+1 보다 크면
        {

            q.push(next);               // 큐 삽입
            dist[next] = dist[now] + 1; //변경
        }
        next = now + 1;                                    //다음 행성지
        if (next <= MAX - 1 && dist[next] > dist[now] + 1) //범위에 있으며 다음 목적지 거리가 현재거리+1 보다 크면
        {
            q.push(next);               //삽입
            dist[next] = dist[now] + 1; //변경
        }
    }

    cout << dist[k] << endl;
}
