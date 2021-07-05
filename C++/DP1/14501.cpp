#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 17
typedef pair<int, int> pai;
typedef vector<int>::iterator iter;

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
int N;
int ans = 0;
pair<int, int> memo[MAX];
int dp[MAX];

int main()
{

    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        int t, p;
        cin >> t >> p;
        pair<int, int> pr = make_pair(t, p);
        memo[i] = pr;
    }

    for (int i = 1; i <= N; i++)
    {

        if (i + memo[i].first <= N + 1) // i 번째 날 일을 했고, 그날 걸리는 날이, 퇴사 날을 넘기지 않을 경우, 퇴사날은 N이지만 ,N날 까지 일했을 경우 N+1로 생각
        {
            //first -> 걸리는 날짜, secnod 그 날의 급여
            //해당날에 근무했을 때 최대 급여는 , 이미 구해졌던 값, 그날 값 만 더한(첫 값을 구할 때 사용하는듯 ,i=1,2,3) 2 값중  max rkqt
            dp[i + memo[i].first] = max(dp[i + memo[i].first], dp[i] + memo[i].second);
            ans = max(ans, dp[i + memo[i].first]);
        }
        //i 번째 날에 일을 하지 않을 때는, 그 다음날 시작전 급여는,그 전 날의 급여와 같다
        dp[i + 1] = max(dp[i + 1], dp[i]);
        // 최대값 갱신
        ans = max(ans, dp[i + 1]);
    }
    cout << ans;
}
