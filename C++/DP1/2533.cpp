#include <bits/stdc++.h>

using namespace std;

#define MAX 1000001
int n;
bool visited[MAX];
vector<int> e[MAX];
int dp[MAX][2]; // 0이 어답터, 1이 일반인

void dfs(const int now)
{
    visited[now] = true;
    dp[now][0] = 1;
    for (const int &next : e[now])
    {
        if (visited[next] == true)
            continue;
        dfs(next);
        dp[now][1] += dp[next][0];                   //현재가 일반인이면 다음은 무조건 어탑터
        dp[now][0] += min(dp[next][0], dp[next][1]); //현재가 어답터이면 다음은 둘중 작은거 선택
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        //이중연결
        e[u].push_back(v);
        e[v].push_back(u);
    }

    dfs(1);
    cout << min(dp[1][0], dp[1][1]);
}