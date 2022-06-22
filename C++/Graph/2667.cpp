#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define tab " "
#define MAX 26
#define P pair<int, int>
int n;
string board[MAX];
vector<int> danzi;
bool isvisit[MAX][MAX];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int main()
{
    //     ios::sync_with_stdio(false);
    // 	cin.tie(NULL);
    // 	cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> board[i];
    }

    int num = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (isvisit[i][j] || board[i][j] == '0')
                continue;
            else
            {
                int cnt = 1;
                queue<P> q;
                q.push({i, j});
                isvisit[i][j] = true;
                while (!q.empty())
                {
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();

                    for (int k = 0; k < 4; k++)
                    {
                        int ny = y + dy[k];
                        int nx = x + dx[k];
                        if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                            continue;
                        if (board[ny][nx] == '0' || isvisit[ny][nx])
                            continue;
                        q.push({ny, nx});
                        isvisit[ny][nx] = true;
                        cnt++;
                    }
                }
                danzi.push_back(cnt);
            }
        }
    }

    sort(danzi.begin(), danzi.end());

    cout << danzi.size() << endl;
    for (int i = 0; i < danzi.size(); i++)
    {
        cout << danzi[i] << endl;
    }
}
