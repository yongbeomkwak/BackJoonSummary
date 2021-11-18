/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> p; // distance,node num

int main()
{
    int v, e;
    int a_cost = 0;
    cin >> v;
    cin >> e;
    vector<int> visit(v + 1, 0);                  // 방문 확인
    vector<vector<p> > graph(v + 1);              //인정행렬
    priority_queue<p, vector<p>, greater<p> > pq; // p -> <distance,dest> distance로 올림차순

    for (int i = 0; i < e; i++)
    {
        int s, d, c;
        cin >> s >> d >> c;
        graph[s].push_back({c, d});
        graph[d].push_back({c, s});
        //양방향 그래프
    }

    long long ret = 0;

    pq.push({0, 1}); //거리 0,1번 노드 부터 탐색

    while (!pq.empty())
    {
        int u = pq.top().second;     //노드 번호
        int u_idst = pq.top().first; //거리
        pq.pop();

        if (visit[u] == 1)
            continue;
        visit[u] = 1; // 방문

        ret += u_idst; // 방문했으니 해당 거리 더함
        for (int i = 0; i < graph[u].size(); i++)
        {
            p edge = graph[u][i]; //인접 노드에 대한 간선 정보
            int v = edge.second;  //u에 대한 인접노드 번호 v

            if (visit[v] == 0)
                pq.push(edge); //v에 대해 방문 여부 확인하고 방문 안했으면 q에 추가
        }
    }

    cout << ret;
}
