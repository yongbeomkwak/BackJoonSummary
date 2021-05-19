#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[102];

int max(int a, int b) { return a > b ? a : b; }
int main()
{
    int N, a, b;
    int result = 0;
    cin >> N;

    vector<pair<int, int> > v;

    for (int i = 0; i < N; i++) //자기 자신은 겹치지 않는 전깃 줄
    {
        dp[i] = 1;
    }

    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &a, &b);
        v.emplace_back(a, b);
    }
    sort(v.begin(), v.end());

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (v[i].second > v[j].second)
            {                                  //secnod는 b의 위치,i번째가 가장 오른쪽에 있다고 하여,만약 j가 더크면 겹친 거임
                dp[i] = max(dp[i], dp[j] + 1); //최대로 겹치지 않는 전기 줄 수
            }
        }
        result = max(result, dp[i]);
    }

    cout << N - result << endl;
    return 0;
}