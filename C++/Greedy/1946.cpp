#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> &p1, pair<int, int> &p2) //first 즉 서류 점수로 오름 차순 정렬(순위 상 내림 차순)
{
    if (p1.first < p2.first)
    {
        return true;
    }
    return false;
}

int main()
{
    int T = 0;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        int result = 0;
        vector<pair<int, int> > v;
        int N = 0;
        scanf("%d", &N);
        for (int i = 0; i < N; i++)
        {
            int first = 0;
            int second = 0;
            scanf("%d %d", &first, &second);             //서류 점수, 면접 점수를 받음
            pair<int, int> p = make_pair(first, second); //pair 객체로 만든 후
            v.push_back(p);                              //백테 삽입
        }
        sort(v.begin(), v.end(), compare); // 서류점수 오름 차순
        int min = v[0].second;             //1등의 면접 점수를 최솟 값으로 초기화

        for (int i = 0; i < N; i++)
        {
            if (min >= v[i].second) //가장 작은 등수(고 등수) 보다 자신이 낮거나 같을 때 합격
            {
                min = v[i].second; // 최소 등수 변경
                result++;          //결과 증가
            }
        }
        printf("%d\n", result);
    }
}