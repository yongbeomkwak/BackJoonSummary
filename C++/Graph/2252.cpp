#include <bits/stdc++.h>

using namespace std;
int main()
{
    int N, M;

    cin >> N >> M;
    vector<vector<int> > graph(N + 1); //그래프
    vector<int> edges(N + 1, 0);       //간선 배열
    for (int i = 0; i < M; i++)
    {
        int A, B;
        cin >> A >> B;         // A->B
        graph[A].push_back(B); //인접 노드
        edges[B]++;            //해당 인덱스에 간선 증가
    }

    queue<int> q;

    for (int i = 1; i < edges.size(); i++)
    {
        if (edges[i] == 0) //간선이 없는 것을 모두 넣는다.
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int i = 0; i < graph[u].size(); i++)
        {
            edges[graph[u][i]]--; //현재 노드(u)의 인접 노드 간선([u][i]) 하나 제거

            if (edges[graph[u][i]] == 0) //만약 해당 노드의 간선이 없을 경우
            {
                q.push(graph[u][i]); //q에 추가
            }
        }
    }
}