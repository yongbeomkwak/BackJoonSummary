#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

typedef struct _Jewelry
{
    int M;
    int V;

} JEWELRY, *PJEWELRYY;

struct comp //비교 구조체
{
    bool operator()(JEWELRY &a, JEWELRY &b)
    {
        if (a.M > b.M) // M기준 내림차순(Top을기준으로)  즉,  M 가 높은게 bottom으로 감
        {
            return true;
        }
        else
            return false;
    }
};

bool v_comp(JEWELRY &a, JEWELRY &b)
{
    if (a.M < b.M) //오름차순
    {
        return true;
    }
    return false;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, K = 0;
    long long int answer = 0;
    cin >> N >> K;
    vector<JEWELRY> v;
    vector<int> bag;
    priority_queue<int, vector<int>, less<int> > temp; // 내림차순 (가장 작은게 바닥에 있음)
    for (int i = 0; i < N; i++)
    {
        int M, V = 0;
        cin >> M >> V;
        JEWELRY j;
        j.M = M;
        j.V = V;
        v.push_back(j);
        /* code */
    }
    for (int i = 0; i < K; i++)
    {
        int C = 0;
        cin >> C;
        bag.push_back(C);
    }
    sort(bag.begin(), bag.end()); //무게 기준 오름 차순
    sort(v.begin(), v.end(), v_comp);

    int idx = 0;
    for (int i = 0; i < K; i++)
    {
        while (idx < N && v[idx].M <= bag[i]) // 현재 가르키는 v가 범위를 벗어나지 않고,그 보석의 무게가 현재 가방의 무게보다 작거나 같을 때
        {
            temp.push(v[idx++].V); // Pq에 현재  담을 수 있는 보석의 가격을 넣고 idx를 증가
        }
        if (!temp.empty()) //비어 있지 않으면
        {
            answer += temp.top(); //가장위엑 지금 담을 수 있는 보석 중 가치가 제일 높은게 담겨 있음
            temp.pop();           // 빼줌
        }
    }

    cout << answer;
}
