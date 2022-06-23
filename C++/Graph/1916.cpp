#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define tab " "
#define MAX 1001
#define P pair<int, int>
int dist[MAX] = {
    0,
};
vector<P> adj[MAX];
bool iscycle = false;
int n, m;
void bm(const int start)
{
    dist[start] = 0;

    for (int k = 0; k < n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (dist[i] == INT_MAX)
                continue;

            for (int j = 0; j < adj[i].size(); j++)
            {
                int v = adj[i][j].first;
                int w = adj[i][j].second;

                if (dist[v] > +dist[i] + w)
                {
                    dist[v] = dist[i] + w;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == INT_MAX)
            continue;

        for (int j = 0; j < adj[i].size(); j++)
        {
            int v = adj[i][j].first;
            int w = adj[i][j].second;

            if (dist[v] > +dist[i] + w)
            {
                iscycle = true;
                return;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        dist[i] = INT_MAX;
    }
    for (int i = 0; i < m; i++)
    {
        int e, v, w;

        cin >> e >> v >> w;
        adj[e].push_back({v, w});
    }

    int dept, dest;
    cin >> dept >> dest;
    bm(dept);

    cout << dist[dest];
}
