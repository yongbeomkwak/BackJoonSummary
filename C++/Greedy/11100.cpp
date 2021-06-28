#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
typedef unsigned long ul;
typedef pair<ul, ul> pul;

int N = 0;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    vector<pul> v;
    priority_queue<pul, vector<pul>, greater<pul> > pq;
    for (int i = 0; i < N; i++)
    {
        ul S, T;
        cin >> S >> T;
        pair<ul, ul> p(S, T);
        v.emplace_back(p);
    }
    sort(v.begin(), v.end());

    pq.push(make_pair(v[0].second, v[0].first)); //강으 종료 시간 기준으로 오름차순

    //pq의 first가 종료 시간
    //v의 first가 시작 시간
    for (int i = 1; i < v.size(); i++)
    {
        //top().first은 가장 빨리 종료되는 시간을 가르키고 있다.
        if (v[i].first < pq.top().first) //현재 강의 시작시간이 ,가장 빨리 종료되는 시간보다 작으면 , 다른 강의실을 사용해야함
        {
            pq.push(make_pair(v[i].second, v[i].first)); // 강의실 추가 배정
        }
        else //그렇지 않으면 현재 시작되는 강의는,top에 있는 강의가 끝나고 그 강의실을 사용할 수 있다는 의미
        {
            pq.pop();                                    //top 강의실 빼줌
            pq.push(make_pair(v[i].second, v[i].first)); // 강의실 추가 배정
            //실제로는 size는 같음 빼고 넣기 때문에  (같은 강의실을 쓴다고 보면됨)
        }
    }
    cout << pq.size();
}
