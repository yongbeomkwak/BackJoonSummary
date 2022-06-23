#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define tab " "
#define MAX 10001
#define P pair<int, int>

int v, e;
vector<P> adj[MAX];
bool isvisit[MAX] = {
    false,
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> v >> e;

    for (int i = 0; i < e; i++)
    {
        int a, b, c;

        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }

    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, 1});
    long long ret = 0;
    while (!pq.empty())
    {
        const int u = pq.top().second;
        const int u_w = pq.top().first;
        pq.pop();

        if (isvisit[u])
            continue;
        isvisit[u] = true;

        ret += u_w;

        for (int i = 0; i < adj[u].size(); i++)
        {
            const int v = adj[u][i].second;
            const int v_w = adj[u][i].first;

            if (isvisit[v])
                continue;

            pq.push({v_w, v});
        }
    }

    cout << ret;
}
