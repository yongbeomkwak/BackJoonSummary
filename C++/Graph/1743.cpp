#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define tab " "
#define MAX 101
#define P pair<int, int>

typedef struct _Node
{
    int y, x, cost;
} node;
int n, m, k;
char arr[MAX][MAX];
bool isvisit[MAX][MAX];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;

    for (int i = 0; i < k; i++)
    {
        int r, c;
        cin >> r >> c;
        arr[r][c] = 1;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (!arr[i][j])
                continue;
            if (isvisit[i][j])
                continue;
            queue<P> q;
            q.push({i, j});
            isvisit[i][j] = true;
            int cnt = 1;
            while (!q.empty())
            {
                int y = q.front().first;
                int x = q.front().second;
                q.pop();

                for (int i = 0; i < 4; i++)
                {
                    int ny = y + dy[i];
                    int nx = x + dx[i];
                    if (ny < 1 || nx < 1 || ny > n || nx > m)
                        continue;
                    if (isvisit[ny][nx])
                        continue;
                    if (arr[ny][nx] == 0)
                        continue;

                    q.push({ny, nx});
                    isvisit[ny][nx] = true;
                    cnt++;
                }
            }
            ans = max(ans, cnt);
        }
    }
    cout << ans;
}
