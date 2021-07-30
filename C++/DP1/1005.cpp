#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 1001
#define endl "\n"
#define tab " "
#define MOD 9901
typedef pair<int, int> pai;
typedef vector<int>::iterator iter;
typedef unsigned long long ull;

int max(const int &a, const int &b)
{
    return a > b ? a : b;
}

int min(const int &a, const int &b)
{
    return a < b ? a : b;
}

bool comp(const int &a, const int &b)
{
    return a > b;
}
int n, t, k, w;
int dp[MAX];
vector<int> *node_info;
int inDegree[MAX]; // 진입 차수 의미
int Time[MAX];
void topologySort()
{
    queue<int> q;
    
    for (int i = 1; i <= n; i++) //출발 지점 찾아서 넣어 준다
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }
    while (inDegree[w]) // 종료지점 진입 차선이 0(즉 도달 했으면 종료)
    {
        if (q.size())
        {
            int curr_node = q.front();
            for (int i = 0; i < node_info[curr_node].size(); i++)
            {
                inDegree[node_info[curr_node][i]]--;        //node_info[curr_node] ->현재 노드에 연결된 노드들[i] 진입 차수를 하나씩 감소
                if (inDegree[node_info[curr_node][i]] == 0) //다음 노드의 진입 차선이 0이면 다음 출발지가 된다
                {
                    q.push(node_info[curr_node][i]); //출발지 삽입
                }
                //다음노드 까지 최소 시간= 그 전 값과 현재 노드 + 다음 건물 건설 시간  비교
                dp[node_info[curr_node][i]] = max(dp[node_info[curr_node][i]], dp[curr_node] + Time[node_info[curr_node][i]]);
            }
            q.pop();
        }
    }
    cout << dp[w] << endl;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;

    while (t--)
    {
        cin >> n >> k;
        node_info = new vector<int>[n + 1];
        for (int i = 1; i <= n; i++)
        {
            cin >> Time[i];
            dp[i] = Time[i];
        }
        for (int i = 1; i <= k; i++)
        {
            int s, e;
            cin >> s >> e;
            node_info[s].push_back(e);
            inDegree[e]++;
        }
        cin >> w;
        topologySort();
        for (int i = 1; i <= n; i++)
        {
            dp[i] = 0;
            inDegree[i] = 0;
            Time[i] = 0;
        }
        delete[] node_info; //할당 해제
    }
}
