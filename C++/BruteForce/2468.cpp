#include <bits/stdc++.h>

using namespace std;
#define MAX 101

int arr[MAX][MAX], copyed[MAX][MAX]; // arr:입력 배열, copyed: 복사배열
int n;
int max_h = 0; //가장 큰 강수량(입력 높이중 최대 높이가 됨)
int ans = 0;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

typedef struct _POINT
{
    int x, y;
} point;

void copyArr() //복사
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            copyed[i][j] = arr[i][j];
        }
    }
}

void getFlooding(int h) //참수
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (copyed[i][j] <= h)
                copyed[i][j] = -1; //해당 h이하면 침수
        }
    }
}

void push_safeArea(vector<point> &v)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (copyed[i][j] != -1)
                v.push_back({i, j}); //안전 지대 ,-1이 아니면 벡터에 삽입
        }
    }
}

int bfs(const int h)
{
    int ret = 0;
    vector<point> v;
    copyArr();        //복사
    getFlooding(h);   //침수
    push_safeArea(v); // 복사

    bool visited[MAX][MAX];
    memset(visited, false, sizeof(visited));
    queue<point> q;

    for (point &p : v)
    {
        q.push({p.x, p.y}); //해당 지대부터 출발

        if (visited[p.x][p.y])
            continue;             //이미 방문했으면 다음 안전지대부터 시작
        visited[p.x][p.y] = true; //방문안했으면 표시
        while (!q.empty())
        {
            int x = q.front().x;
            int y = q.front().y;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                const int nx = x + dx[i];
                const int ny = y + dy[i];

                if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                    continue; //범위를 벗어났거나
                if (visited[nx][ny])
                    continue; //방문했으면 넘어감

                if (copyed[nx][ny] != -1) //만약 다음 지역이 -1이 아니면 방문후 삽입
                {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
        ret++; //큐가 끝났으면 하나의 안전지역을 묶은 것
    }

    return ret; //해당 높이로 계산한 안전지역 갯수 리턴
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            max_h = max(max_h, arr[i][j]);
        }
    }

    for (int i = 0; i <= max_h; i++)
    {
        ans = max(ans, bfs(i)); // 0부터 최대 높이까지 중 최대 안전지대 리턴
    }

    cout << ans;
}
