/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define P pair<int, int>
#define endl "\n"
#define ll long long
bool iscycle = false;

void bellman_ford(vector<vector<P> > &adj, vector<ll> &dist)
{
    dist[1] = 0;                          //1번 마을 거리를 0으로 변경 후
    for (int i = 1; i < dist.size(); i++) //가장 중요:vertexs 갯수만큼 반복해야함
    //이유 밑에 반복문에서 업데이트 됬을 때 다시 처음부터 적용 시켜야 하므로
    {
        for (int u = 1; u < dist.size(); u++) // 출발 마을을 1번 마을부터 n번 마을 까지 돌며  (dist.size()=n+1)
        {
            if (dist[u] == INT_MAX)
                continue; //출발 마을 자체가 무한대면 출발마을로 이전에 도착할 길이 없음

            for (int j = 0; j < adj[u].size(); j++) //출발 마을 u로부터 인접 마을들을 돈다.
            {
                int v = adj[u][j].first;   //다음 마을
                int w = adj[u][j].second;  //다음 마을까지 걸리는 시간
                if (dist[u] + w < dist[v]) //다음 마을까지 최소 시간이, 이전마을 시간 + 다음 마을까지 걸리는 시간 비교
                {
                    dist[v] = dist[u] + w; //작을 경우 업데이트
                }
            }
        }
    }
    //한번더 반복하며 Negative Recycle을 찾는다.
    for (int i = 1; i < dist.size(); i++)
    {
        int u = i;
        if (dist[u] == INT_MAX)
            continue;

        for (int j = 0; j < adj[u].size(); j++)
        {
            int v = adj[u][j].first;
            int w = adj[u][j].second;
            if (dist[u] + w < dist[v]) //여전히 계산값이 최솟값이 존재하면 Negative cycle 존재
            {
                iscycle = true; //true
                return;         //
            }
        }
    }
}

int main()
{

    int n, m;
    cin >> n >> m;
    vector<vector<P> > adj(n + 1);
    vector<ll> dist(n + 1, INT_MAX);

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    bellman_ford(adj, dist);

    if (iscycle) //사이클 존재 시 -1 출력후
    {
        cout << -1 << endl;
    }

    else
    {
        for (int i = 2; i <= n; i++)
        {
            if (dist[i] == INT_MAX) //여전히 무한대를 가르킬 시 -1
            {
                cout << -1 << endl;
                continue;
            }
            cout << dist[i] << endl; //아닐경우 저장된 최소 거리 출력
        }
    }
}
