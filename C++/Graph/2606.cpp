#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define tab " "
#define MAX 101
#define P pair<int, int>

int n, m;
vector<int> adj[MAX];
bool is_visit[MAX] = {
    false,
};
int main()
{
    // os::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    cin >> n;
    cin >> m;

    queue<int> q;
    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        if (a == 1)
        {
            q.push(b);
            cnt++;
            is_visit[b] = true;
        }
        else if (b == 1)
        {
            q.push(a);
            cnt++;
            is_visit[a] = true;
        }
    }
    is_visit[1] = true;
    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        for (int i = 0; i < adj[now].size(); i++)
        {
            int next = adj[now][i];
            if (is_visit[next])
                continue;
            is_visit[next] = true;
            cnt++;
            q.push(next);
        }
    }

    cout << cnt;
}
