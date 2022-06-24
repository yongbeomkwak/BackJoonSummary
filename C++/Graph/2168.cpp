#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define tab " "
#define MAX 51

typedef struct _NODE
{
    int y, x, cost;
} node;

#define P pair<int, int>

int n, m;

int dir[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
bool Visit[MAX][MAX];
int arr[MAX][MAX];
vector<node> v;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (!arr[i][j])
                v.push_back({i, j, 0});
        }
    }

    int ans = 0;

    for (int k = 0; k < v.size(); k++)
    {
        int i = v[k].y;
        int j = v[k].x;
        queue<node> q;
        q.push({i, j, 0});
        Visit[i][j] = true;

        while (!q.empty())
        {
            int y = q.front().y;
            int x = q.front().x;
            int cost = q.front().cost;
            q.pop();
            if (arr[y][x])
            {

                ans = max(ans, cost);
                break;
            }

            for (int i = 0; i < 8; i++)
            {
                int ny = y + dir[i][0];
                int nx = x + dir[i][1];
                if (nx < 0 || ny < 0 || ny >= n || nx >= m)
                    continue;
                if (Visit[ny][nx])
                    continue;
                Visit[ny][nx] = true;
                q.push({ny, nx, cost + 1});
            }
        }
        memset(Visit, false, sizeof(Visit));
    }

    cout << ans;
}
