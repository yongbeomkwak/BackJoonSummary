#include <bits/stdc++.h>

using namespace std;

vector<int> parent;

int find_parent(const int i)
{
    int rt = parent[i];

    while (rt != parent[rt])
        rt = parent[rt];

    int c = i;

    // path compression(시간 복잡도를 나중에 갈수록 줄이기 위해)
    while (c != parent[c])
    {
        int pc = parent[c];
        parent[c] = rt;
        c = pc;
    }

    return rt;
}

void _union(int a, int b)
{
    const int pa = find_parent(a);
    const int pb = find_parent(b);

    if (pa < pb)
    {
        parent[pb] = pa;
    }
    else
    {
        parent[pa] = pb;
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    int ans = 0;
    cin >> n >> m;
    parent = vector<int>(n, 0);

    for (int i = 0; i < n; i++) //처음은 자기자신
    {
        parent[i] = i;
    }

    for (int i = 1; i <= m; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        int d1 = min(t1, t2);
        int d2 = max(t1, t2);
        //둘 중 작은 것은 d1 큰 것은 d2로 놓고

        int pd1 = find_parent(d1);
        int pd2 = find_parent(d2);
        // union 즉 합치기전에 부모들이 같은지 검사해보고
        //만약 같다면 이번 차례 간선연글을 하면 사이클이 생김
        if (pd1 == pd2)
        {
            ans = i;
            break;
        }
        else //부모가 다르면 union작업
        {
            _union(d1, d2);
        }
    }
    cout << ans;
}
