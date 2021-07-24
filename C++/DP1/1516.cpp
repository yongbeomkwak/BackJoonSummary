#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 501
#define endl "\n"
#define tab " "
#define MOD 9901
#define INF 987654321
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

int n;
int dp[MAX];
vector<int> build[MAX];
int _time[MAX];
int inDegree[MAX];

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int __time;
        cin >> __time;
        _time[i] = __time;
        while (1)
        {
            int node; //해당 건물을 완성시키기 전에 완성 시켜야할 건물들
            cin >> node;
            if (node == -1)
            {
                break;
            }
            inDegree[i]++;
            build[node].push_back(i); // 해당 i를 짓기위해 node가 필요하므로, node에 넣어준다 i를 넣어준다
        }
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (inDegree[i] == 0) // i가 0이란 뜻은 해당 건물을 짓기위한 node가 없다는 뜻
        {
            q.push(i); //출발지로 넣어줌
        }
    }

    //dp[i] = i 건물 짓기전 최소시간
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int i = 0; i < build[node].size(); i++) //0 build[node][i] => node가 필요한 건물들의 배열, 즉 준비물이 node임
        {
            int nextNode = build[node][i];                            // nextNode , node를 만든 후 만들 수 있는 건물
            dp[nextNode] = max(dp[nextNode], dp[node] + _time[node]); // nextNode를 만들 수 있는 시간은 = 현재값과 , 이전 건물  완성 시간=dp[node](node 짓기전 최소 시간)+_time(node 짓는 시간)
            if (--inDegree[nextNode] == 0)                            // 모든 진입 차선이 없는 가 ,즉  nextNode를 짓기위해 필요한 건물이 없는가
            {
                q.push(nextNode);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << dp[i] + _time[i] << endl; // dp[i]= i 짓기전 최소시간 , + _time[i] i 건물 짓는 시간 = i 번째까지 짓는 최소시간
    }
}
