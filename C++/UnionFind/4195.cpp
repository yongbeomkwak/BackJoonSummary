#include <bits/stdc++.h>

using namespace std;
#define MAX 200003
#define endl "\n" //시간 초과를 위해 개행문자

int parent[MAX];
int children[MAX];
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

int _union(int a, int b)
{
    const int pa = find_parent(a);
    const int pb = find_parent(b);
    int ret = 0;

    if (pa != pb)
    {
        if (children[pa] < children[pb]) //만약 pb가 더 많은 자식을 둔다면
        {
            children[pb] += children[pa]; // 자식을 흡수하고
            ret = children[pb];
            parent[pa] = pb; // pa의 부모는 pb가 된다.
        }
        else
        {
            //반대로
            // pa가 더많은 자식을 갖고 있다면  pb자식이 pa에 흡수
            children[pa] += children[pb];
            ret = children[pa]; // 그 결과를 저장하고
            parent[pb] = pa;    // pb의 부모가 pa가 된다.
        }
    }
    else //만약 pa와 pb가 같다면
    {
        ret = children[pa]; // pa의 개수를 저장한다.
    }

    return ret;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;

    while (tc--)
    {
        int f;
        cin >> f;
        for (int i = 0; i <= f * 2; i++) //부모 최고하
        {
            parent[i] = i;   // 자신의 부모는 처음 자기 자신
            children[i] = 1; // i가 가지고 있는 자식 개수 일단 초기화는 자기자신
        }

        unordered_map<string, int> _hash; //해당 친구이름을 번호로 매핑

        int idx = 0; // 해당 이름을 int로 매핑하기 위한 인덱스 번호
        for (int i = 0; i < f; i++)
        {
            string f1, f2;
            cin >> f1 >> f2;

            if (_hash.find(f1) == _hash.end())
                _hash[f1] = idx++;
            if (_hash.find(f2) == _hash.end())
                _hash[f2] = idx++;

            cout << _union(_hash[f1], _hash[f2]) << endl; //합친 후 해당 자식 개수 리턴
        }
    }
}
