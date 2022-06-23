#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define tab " "
#define MAX 101
#define P pair<int, int>

int n, m;
char arr[MAX][MAX];
bool isvisit[MAX][MAX];
int dx[] = {0, 0, -1, 1};
int dy[] = {
    1,
    -1,
    0,
    0,
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    vector<int> ans(2, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (isvisit[i][j])
                continue;
            char now = arr[i][j];
            queue<P> q;

            q.push({i, j});
            isvisit[i][j] = true;
            int cnt = 0;
            while (!q.empty())
            {
                int c_i = q.front().first;
                int c_j = q.front().second;
                q.pop();
                cnt++;

                for (int i = 0; i < 4; i++)
                {
                    int n_i = c_i + dy[i];
                    int n_j = c_j + dx[i];
                    if (n_j < 0 || n_i < 0 || n_i >= n || n_j >= m)
                        continue;
                    if (isvisit[n_i][n_j])
                        continue;
                    if (arr[n_i][n_j] == now)
                    {
                        q.push({n_i, n_j});
                        isvisit[n_i][n_j] = true;
                    }
                }
            }

            if (now == 'W')
                ans[0] += cnt * cnt;
            else
                ans[1] += cnt * cnt;
        }
    }

    cout << ans[0] << tab << ans[1];
}
