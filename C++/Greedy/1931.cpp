#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

#define LMIT 100001

typedef struct _Time
{
    int start;
    int end;
} Time;

bool comp(Time &t1, Time &t2)
{
    if (t1.end == t2.end)
        return t1.start < t2.start; //종료시간이 같을 경우 시작시간이 작은 순
    else
        return t1.end < t2.end; //아니면 종료시간이 작을 때
}

using namespace std;
int main()
{
    int n = 0;
    scanf("%d", &n);
    vector<Time> v(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &v[i].start, &v[i].end);
    }
    sort(v.begin(), v.end(), comp); //먼저 정렬함
    int endTime = 0;                //바로 직전 회의 종료시간
    int cnt = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (endTime <= v[i].start) //다음 회의 시작시간이 바로 직전 종료시간보다 크거나 같으면 회의가 가능
        {
            endTime = v[i].end; //종료시간 변경
            cnt++;              //증가
        }
    }
    printf("%d", cnt);
}