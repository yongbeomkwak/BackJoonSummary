#include <bits/stdc++.h>

using namespace std;

#define MAX 101
#define INF 987654321
int n, m;

int adj[MAX][MAX]; //글로벌로 선언하여 초기값 0

int main()
{

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                continue;
            else
                adj[i][j] = INF; //출발(i)와 도착지점(j)이 다르면 INF
        }
    }

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a][b] = 1; //서로연결시 weight 1
        adj[b][a] = 1; //서로 연결
    }

    for (int k = 1; k <= n; k++) //거쳐가는 노드
    {
        for (int i = 1; i <= n; i++) //출발 노드
        {
            for (int j = 1; j <= n; j++) //도착 노드
            {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]); //플로이드 와샬
            }
        }
    }

    int ret = INF;
    int kevin_bacon_number = 1;
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int j = 1; j <= n; j++)
        {
            sum += adj[i][j];
        }
        if (ret > sum)
        {
            kevin_bacon_number = i;
        }
        ret = min(ret, sum);
    }

    cout << kevin_bacon_number; //자신을 제외한 모든 노드에 대한 간선의 합이 최소인 노드 번호 출력
}
