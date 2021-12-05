/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;
#define INF 987654321
#define MAX 10001

int village[MAX];
vector<int> adj[MAX];
int _visit[MAX];
int wines[MAX];
int dp[MAX][2];

void dfs(int now)
{
    _visit[now] = 1;

    for (int i = 0; i < adj[now].size(); i++)
    {
        int next = adj[now][i];
        if (_visit[next] == 1)
            continue; //방문 했다면 넘어감
        dfs(next);

        //탐색을 모두 끝낸 후
        dp[now][0] += max(dp[next][0], dp[next][1]); //현재 마을이 일반 마을이면 다음 마을이 어떤 마을이던 상관 없음
        dp[now][1] += dp[next][0];                   //현재 마을이 우수마을이면 그 다음은 우수마을이 되면 안됨
    }
}

int main()
{
    int n = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int citizens;
        cin >> citizens;
        village[i] = citizens;
    }
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = 0;
        dp[i][1] = village[i];
    }

    dfs(1);
    cout << max(dp[1][1], dp[1][0]);
}
