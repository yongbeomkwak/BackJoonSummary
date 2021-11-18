/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

typedef struct _Edge
{
    int src;
    int dest;
    int cost;
} edge, *Pedge;

struct cmp
{
    bool operator()(const edge &e1, const edge &e2)
    {
        return e2.cost < e1.cost; //cost별 오름차순
    }
};

int find(const int i, vector<int> &roots)
{
    //루트를 찾는다.
    if (roots[i] == i)
        return i;                            //해당 노드의 루트가 자기자신이 면 자기자신 리턴
    return roots[i] = find(roots[i], roots); // 아니면 i노드의 root인 root[i]의 root를 탐색하러 간다.
}

void merge(const int i, const int j, vector<int> &roots)
{
    int x = find(i, roots); //i의 루트 x
    int y = find(j, roots); //j의 루트 y
    //각 루트를 찾는다.
    // x->y 이기 때문에 병합 시 y의 부모는 x가 된다.

    if (x == y)
        return;   //둘이 같으면 리턴
    roots[y] = x; //같지 않을 경우 y의 부모는 x가 된다.
}

bool isUnion(const int i, const int j, vector<int> &roots)
{
    int x = find(i, roots); //i의 루트인 x
    int y = find(j, roots); //y의 루트인 y
    if (x == y)             //둗 부모가 같으면 이미 같은 집합 ,아니면 false
    {
        return true;
    }
    return false;
}

int main()
{
    int v, e;
    int a_cost = 0;
    cin >> v;
    cin >> e;
    priority_queue<edge, vector<edge>, cmp> pq; //cost오름 차순으로 edge구조체를 넣는다.
    vector<int> roots(v + 1);
    for (int i = 0; i < e; i++)
    {
        int s, d, c;
        cin >> s >> d >> c;
        pq.push({s, d, c});
    }

    for (int i = 0; i <= v; i++)
        roots[i] = i; //root 배열 초기화시 처음은 자기 자신으로 한다.

    while (!pq.empty())
    {
        if (!isUnion(pq.top().src, pq.top().dest, roots)) //만약 둘이 같은 집합이 아니면(src,dest) 병합이 필요함
        {
            a_cost += pq.top().cost;                   //병합 하기 위한 비용
            merge(pq.top().src, pq.top().dest, roots); //병합
        }
        pq.pop(); //간선 제거
    }
    cout << a_cost;
}
