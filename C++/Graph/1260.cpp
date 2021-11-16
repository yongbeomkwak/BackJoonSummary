#include <bits/stdc++.h>

#define MAX 1001

int isVisit[MAX];
int adj[MAX][MAX];
int N;
using namespace std;

void dfs(const int source)
{
    isVisit[source] = 1;
    cout << source << " ";
    for (int i = 1; i <= N; i++)
    {
        if (isVisit[i] == 0 && adj[source][i] == 1) //인접행렬 중 방문 하지 않은 것을 dfs,adj[source][i]==1[source와 i는 연결되어 있다.]
        {
            dfs(i);
        }
    }
}

void bfs(const int source)
{
    queue<int> q;
    isVisit[source] = 1; //시작점은 방문 처리
    q.push(source);
    cout << source << " "; //시작 출력

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int i = 1; i <= N; i++)
        {
            if (adj[u][i] == 1 && isVisit[i] == 0) //u와 연결되어 있는 노드 i면서 아직 방문하지 않았다면
            {
                q.push(i);      //q에 삽입
                isVisit[i] = 1; // 방문 처리
                cout << i << " ";
            }
        }
    }
}

void reset()
{
    for (int i = 1; i <= N; i++)
    {
        isVisit[i] = 0;
    }
}

int main()
{
    int E, V;

    cin >> N >> E >> V;
    for (int i = 0; i < E; i++)
    {
        int a, b;
        cin >> a >> b;
        //양방향 간선
        adj[a][b] = 1;
        adj[b][a] = 1;
    }

    dfs(V);
    cout << "\n";
    reset();
    bfs(V);
}