#include <bits/stdc++.h>

using namespace std;

#define MAX 101
#define P pair<int, int>
int m, n, k;

int _map[MAX][MAX] = {
    0,
}; // 전체 맵을 0으로

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
//상하 좌우 움직임
int main()
{

    cin >> m >> n >> k;

    for (int i = 0; i < k; i++)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int j = y1; j <= y2 - 1; j++) // y1~y2-1 까지 -1로
        {
            for (int t = x1; t <= x2 - 1; t++) // x1~x2-1까지 -1로
            {
                _map[j][t] = -1;
            }
        }
    }

    vector<int> areas;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            //모든 정점을 봤을 때 0이아니면 아직 탐색 안한 것
            if (!_map[i][j] == 0)
                continue;

            queue<P> q; // 0이면 탐색을 해야하므로 큐에 삽입
            q.push({i, j});
            _map[i][j] = -1; //탐색 하는 점이므로 -1로
            int cnt = 1;     //시작 넓이 1
            while (!q.empty())
            {
                const int y = q.front().first;
                const int x = q.front().second;

                q.pop();

                // bfs
                for (int t = 0; t < 4; t++)
                {
                    const int ny = y + dy[t];
                    const int nx = x + dx[t];
                    if (ny < 0 || nx < 0 || ny >= m || nx >= n)
                        continue; //범위를 벗어나면
                    if (_map[ny][nx] == -1)
                        continue;      //이미 탐색했으면
                    _map[ny][nx] = -1; //아직 탐색하지 않았으면 -1

                    q.push({ny, nx}); // 해당 좌표 삽입
                    cnt++;            //넓이 증가
                }
            }
            areas.push_back(cnt);
        }
    }

    sort(areas.begin(), areas.end()); //오름 차순 정렬

    cout << areas.size() << endl;
    for (int i = 0; i < areas.size(); i++)
    {
        cout << areas[i] << " ";
    }

    return 0;
}
