#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int> > vvi;
typedef vector<int> vi;
typedef stack<int> sti;
#define endl "\n"

void dfs(const int v, vvi &graph, vi &visit, sti &st)
{
    visit[v] = 1;

    for (int i = 0; i < graph[v].size(); i++)
    {
        int next = graph[v][i]; //DFS 진행
        if (visit[next] == 0)
            dfs(next, graph, visit, st);
    }
    st.push(v); //끝나는 순으로 넣기(도착하는 순의 반대)
}

void reDfs(const int v, const int scc_num, vvi &graph, vi &visit, vvi &sccs)
{

    visit[v] = 1;
    sccs[scc_num].push_back(v); //해당 scc_num 자리에 해당 노드를 넣는다
    for (int i = 0; i < graph[v].size(); i++)
    {
        int next = graph[v][i]; //DFS 진행
        if (visit[next] == 0)
        {
            reDfs(next, scc_num, graph, visit, sccs);
        }
    }
}

int main()
{
    int V, E;
    cin >> V >> E;
    vvi graph(V + 1);   //그래프
    vvi graphT(V + 1);  //역그래프
    vi visit(V + 1, 0); //방문 확인
    vvi sccs(V + 1);    //SCC의 벡터
    sti st;             //스택

    for (int i = 0; i < E; i++)
    {
        int A, B;
        cin >> A >> B;
        graph[A].push_back(B);
        graphT[B].push_back(A);
        //역으로 넣어줌
    }

    for (int i = 1; i <= V; i++)
    {
        if (visit[i] == 0)
            dfs(i, graph, visit, st);
    }
    fill(visit.begin(), visit.end(), 0); //역그래프에 dfs를 하기위해 다시 초기화

    int scc_num = 0;

    while (!st.empty())
    {
        int s = st.top();
        st.pop();
        if (visit[s] == 1)
            continue;

        reDfs(s, scc_num, graphT, visit, sccs);
        scc_num++; //dfs한번 끝나면 그룹 하나가 생성된 것이니 그룹 증가
    }
    cout << scc_num << endl;
    vector<pair<int, int> > ret;
    for (int i = 0; i < scc_num; i++)
    {
        sort(sccs[i].begin(), sccs[i].end());    //해당 scc들의 노드들을 오름차순으로 정렬
        ret.push_back(make_pair(sccs[i][0], i)); //scc들의 가장 앞 노드와, 해당 그룹 번호를 담음
    }
    sort(ret.begin(), ret.end()); // scc의 첫 번째 노드를 기준으로 오름차순 정렬

    for (const pair<int, int> &p : ret) //각 scc들의 첫번 째 노드로 오름차순이 끝난 후,해당 노드와 연결된 scc그룹 번호(second)대로 출력
    {
        for (const int &node : sccs[p.second]) //sccs 벡터에서 해당 그룹 번호에 해당하는 노드들을 출력한다
        {
            cout << node << " ";
        }
        cout << "-1" << endl;
    }
}