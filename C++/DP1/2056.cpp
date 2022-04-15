#include <bits/stdc++.h>

using namespace std;

#define MAX 10001
int n;

int times[MAX] = {
    0,
};

int dp[MAX] = {
    0,
};
int edges[MAX] = {
    0,
};
vector<int> graph[MAX];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    int ret = 0;
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> times[i];
        dp[i] = times[i];
        int edge;
        cin >> edge;
        edges[i] = edge;

        for (int j = 0; j < edge; j++)
        {
            int pre;
            cin >> pre;
            graph[pre].push_back(i); // pre-> i ,pre에서 i로 들어오는 간선 입력
        }
    }

    for (int i = 1; i <= n; i++)
        if (edges[i] == 0) // 들어오는 간선이 없는 애들 담음
            q.push(i);

    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        for (int i = 0; i < graph[now].size(); i++)
        {
            int next = graph[now][i];                        // now의 다음 목적지
            dp[next] = max(dp[next], dp[now] + times[next]); // next의 dp시간과,현재 + next 시간 중 큰 값 사용
            edges[next]--;                                   //
            if (edges[next] == 0)                            //이제 next로 들어갈 수 있다면(next를 처리할 수 있다면)
                q.push(next);
        }
    }

    for (int i = 1; i <= n; i++)
        ret = max(ret, dp[i]);
    cout << ret;
}