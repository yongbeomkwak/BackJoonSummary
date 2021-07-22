#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 16
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
int cost[MAX][1 << MAX]; //최대 16개의 도시의 방문 상태를 표현하기 위해
int map[MAX][MAX];
int answer_bit;

int DFS(const int &curr_node, const int &curr_bit)
{
    if (curr_bit == answer_bit) //현재 비트와 목표 비트가 같으면 모든 마을을 돌고 온 것
    {
        //모든 마을을 돌고 있는 도중, 0로 들어가는 길이 0일 경우 순회 불가 , 아닐경우 해당 값 리턴
        if (map[curr_node][0] == 0)
            return INF;
        return map[curr_node][0];
    }
    if (cost[curr_node][curr_bit] != -1) //해당 가중치가 -1아니면 리턴 (-1은 밑에서 memset으로 설정,0은 벽이기 때문에 -1로 설정,즉 방문 하면안되는 구간(n범위 벗어난)이 -1)
        return cost[curr_node][curr_bit];
    cost[curr_node][curr_bit] = INF; // 맞을 경우 최소값을 구하기 위해 초반에 최대값을 설정합니다.(-1)

    for (int i = 0; i < n; i++)
    {
        if (map[curr_node][i] == 0) //만약 해당 값이 0 이면 , 가지 못하는 장소 이므로 continue
            continue;
        if ((curr_bit & (1 << i)) == (1 << i)) // 만약 현재 비트와 현재노드의 방문 상태를 (&) check했을 때 같디는 것은  이미 방문했다는 것 continue 돌림
            continue;
        //여기 왔다는 것은 방문 하지도 않고 벽도 아니라는 뜻
        cost[curr_node][curr_bit] = min(cost[curr_node][curr_bit], map[curr_node][i] + DFS(i, curr_bit | 1 << i)); //현재 상태와, map(가중치(현재노드->다음노드))+ 다음노드로 진행(i(다음노드),curr_bit|1<<i(다음 노드 방문했다고 or연산))
    }
    return cost[curr_node][curr_bit];
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }
    answer_bit = (1 << n) - 1; //n이 5일경우 31 -> 11111 가 들어가게 된다

    /*
또한, DFS함수를 가장 초기에 호출할 때 ,모든 정점에서 호출할 필요가 없다. 단순히 0번 정점에서 한번만 호출을 하더라도

   정답을 구할 수가 있다.

   그 이유는 다음과 같은 상황을 보자.

   예를 들어서 0 ~ 4번 총 5개의 도시가 존재하고, 이 도시를 순회하는 최소 비용이 드는 루트가

   0 → 1 → 2 → 3 → 4 → 0 이라고 가정해보자. 이 때, 'A원' 이라는 비용이 들었다고 가정해보면,

   2 → 3 → 4 → 0 → 1 → 2 의 최소비용은 얼마일까? 당연히 'A원' 일 것이다.

*/
    //DFS(현재 정점,현재 방문한 노드의 방문 상태)
    memset(cost, -1, sizeof(cost)); // 잘
    cout << DFS(0, 1) << endl;      // 0에서 출발하여  로 들어감 (출발지와 목적지는 크게 상관없음 DFS이기 땨문에)
}
