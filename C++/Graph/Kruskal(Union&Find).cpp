#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define tab " "
#define MAX 10001
#define P pair<int, int>
typedef struct _Edge
{
    int src, dest, w;
} edge;
struct cmp
{
    bool operator()(const edge &e1, const edge &e2)
    {
        return e2.w < e1.w;
    }
};
int v, e;
int root[MAX];

int find(const int i)
{
    int rt = root[i];  //현재 너드의 부모

    while (rt != root[rt])
    {
        rt = root[rt];
    }
    //rt는 가장 상위 부모
    int c = i;
    //path compression(시간 복잡도를 나중에 갈수록 줄이기 위해)
    while (c != root[c]) //원래 i부터 최상위 부모 까지 모든 부모 노드를 최상위 부모로 바꿈
    {
        int pc = root[c]; //현재 c의 부모, 잠시 저장
        root[c] = rt; //최상위 부모로 변경 
        c = pc;//  다음 부모로 이동 
    }
    return rt;
}

void _union(const int i, const int j)
{
    const int p_i = find(i);
    const int p_j = find(j);

    if (p_i < p_j)
    {
        root[p_j] = p_i;
    }
    else
    {
        root[p_i] = p_j;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> v >> e;

    for (int i = 1; i <= v; i++)
    {
        root[i] = i;
    }
    priority_queue<edge, vector<edge>, cmp> pq;
    for (int i = 0; i < e; i++)
    {
        int src, dest, w;
        cin >> src >> dest >> w;
        pq.push({src, dest, w});
    }

    int ans = 0;
    while (!pq.empty())
    {
        int u = pq.top().src;
        int v = pq.top().dest;
        int w = pq.top().w;
        pq.pop();

        if (find(u) != find(v))
        {
            _union(u, v);
            ans += w;
        }
    }

    cout << ans;
}
