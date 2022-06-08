#include <bits/stdc++.h>

using namespace std;

#define MAX 1001
#define P pair<int, int>
#define INF 100000000
int n, m;

vector<P> graph[MAX];

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    cin >> m;
    int dist[MAX];
    for (int i = 0; i <= n; i++)
    {
        dist[i] = INF;
    }
    for (int i = 0; i < m; i++)
    {
        int s, e, cost;
        cin >> s >> e >> cost;
        graph[s].push_back({cost, e});
    }
    int a, b;

    cin >> a >> b;

    priority_queue<P, vector<P>, greater<P>> pq;
    dist[a] = 0;
    pq.push({0, a});

    while (!pq.empty())
    {
        int now_cost = pq.top().first;
        int depart_node = pq.top().second;
        pq.pop();

        if (dist[depart_node] < now_cost)
            continue; //만약 현재 노드의 최소거리 현재 비용보다 적다면 검사필요 없음
        for (const P &arrive_node : graph[depart_node])
        {
            const int next_cost = arrive_node.first + now_cost;
            const int next_node = arrive_node.second;

            if (dist[next_node] <= next_cost)
                continue;

            dist[next_node] = next_cost;
            pq.push({next_cost, next_node});
        }
    }

    cout << dist[b];

    return 0;
}
