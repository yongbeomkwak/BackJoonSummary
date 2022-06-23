#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define tab " "
#define MAX 1000000000
#define P pair<int, int>
int n;
vector<long long> nums;
int opers[4]; // 0:plus,1:minus,2:multi,3:div
long long _max = -MAX;
long long _min = MAX;

void task(const int use_opers, vector<long long> v)
{
    if (use_opers == n - 1) //연사자를 모두 사용했으면 최종 남아있는 값과 비교
    {
        _max = max(v[0], _max);
        _min = min(v[0], _min);
        return;
    }

    for (int i = 0; i < 4; i++)
    {

        if (!opers[i])
            continue;

        vector<long long> tmp = v;
        //가장 앞(begin)을 제거하기 위해, 연산 결과를 1번 인덱스에 젖ㅇ
        if (i == 0) //합
        {
            tmp[1] += tmp[0];
        }
        else if (i == 1) // 차
        {
            tmp[1] = tmp[0] - tmp[1];
        }
        else if (i == 2) //곱
        {
            tmp[1] *= tmp[0];
        }
        else //나누기
        {
            tmp[1] = tmp[0] / tmp[1];
        }
        tmp.erase(tmp.begin());   //아 제거
        opers[i] -= 1;            //사용한 오퍼레이터 감소
        task(use_opers + 1, tmp); //다음 재귀
        opers[i] += 1;            // 백트래킹
    }
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        long long tmp;
        cin >> tmp;
        nums.push_back(tmp);
    }

    for (int i = 0; i < 4; i++)
    {
        int oper;
        cin >> oper;
        opers[i] = oper;
    }

    task(0, nums);
    cout << _max << endl
         << _min;

    return 0;
}
