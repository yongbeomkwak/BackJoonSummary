#include <bits/stdc++.h>

using namespace std;

#define MAX 52
#define INF 987654321

int n;
int capacity[MAX][MAX]; //capacity[i][j] -> i 에서  j로 갈 때 용량
int flow[MAX][MAX];     //flow[i][j] -> i에서 j로 가는 흐름
vector<int> adj[MAX];   //배열안에 벡터 [i] 에 인접 노드
int Prev[MAX];          //Prev[i]=i의 이전 노드번호

int ctoi(const char c)
{
    if (c <= 'Z')
        return c - 'A'; // 대문자가 소문자보다 아스키 코드 작다.
    return c - 'a' + 26;
}

void bfs(const int start, const int end) //bfs
{
    queue<int> q;
    q.push(start); //시작 넣어 주고

    while (!q.empty() && Prev[end] == -1) // 큐가 비어있지 않았으며 마지막 꺼는 아직 방문하지 않은 상태
    {
        int u = q.front();
        q.pop();
        if (u == end)
            break;

        for (const int &v : adj[u])
        {
            if (Prev[v] == -1 && capacity[u][v] - flow[u][v] > 0) //아직 이전 노드가 없고(방문x) 잔류 용량이 남아있으면
            {
                q.push(v);
                Prev[v] = u; //이전 경로 기억
            }
        }
    }
}

int main()
{

    cin >> n;
    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        char a, b;
        int c;
        cin >> a >> b >> c;
        capacity[ctoi(a)][ctoi(b)] += c; //병렬 연결 시 중첩
        capacity[ctoi(b)][ctoi(a)] += c; //병렬 연결 시 중첩
        adj[ctoi(a)].push_back(ctoi(b)); //간선 추가
        adj[ctoi(b)].push_back(ctoi(a)); //간선 추가
    }
    int start = ctoi('A');
    int end = ctoi('Z');

    while (1)
    {
        memset(Prev, -1, sizeof(Prev)); // 다시 초기화
        bfs(start, end);                //bfs 진행

        if (Prev[end] == -1)
            break; // end로 가는 노드가 없을 경우 멈춤 더이상 argument path가 없을 때

        int max_flow = INF;

        for (int i = end; i != start; i = Prev[i]) //end부터 start까지 이전으로(Prev[i])
        {
            //각 edge별 flow 확인
            max_flow = min(max_flow, capacity[Prev[i]][i] - flow[Prev[i]][i]); //용량-현재 흐르는 량
            //현재 최대 흐름은 현재 최대흐름과,잔류 용량 비교
        }

        for (int i = end; i != start; i = Prev[i]) //end부터 start까지 이전으로(Prev[i])
        {
            //같은 방향은 흘려주고
            flow[Prev[i]][i] += max_flow;
            //반대방향은 막아주고
            flow[i][Prev[i]] -= max_flow;
        }

        ret += max_flow;
    }
    cout << ret << endl;
}
