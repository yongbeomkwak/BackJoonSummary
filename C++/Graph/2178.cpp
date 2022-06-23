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
int n, m;
char arr[MAX][MAX];
bool isvisit[MAX][MAX];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
        }
    }

    int ans = 10001;
    queue<node> q;
    q.push({1, 1, 1});
    isvisit[1][1] = true;
    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        int cost = q.front().cost;
        if (x == m && y == n)
        {
            ans = min(ans, cost);
        }
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 1 || ny < 1 || nx > m || ny > n)
                continue;
            if (arr[ny][nx] == '0')
                continue;
            if (isvisit[ny][nx])
                continue;
            q.push({ny, nx, cost + 1});
            isvisit[ny][nx] = true;
        }
    }

    cout << ans;
}
