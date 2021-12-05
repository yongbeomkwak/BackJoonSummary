/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;
#define INF 987654321
#define MAX 10001
#define P pair<int, int>

int main()
{
    int p, f;
    cin >> p >> f;
    int ans = 0;
    priority_queue<P, vector<P>, greater<P> > pq;
    for (int i = 0; i < p; i++)
    {
        int pump;
        cin >> pump;
        pq.push({pump, 0}); //소화전은 second 0
    }
    for (int i = 0; i < f; i++)
    {
        int fireEngine;
        cin >> fireEngine;
        pq.push({fireEngine, 1}); //소방차는 second 1을 넣어 구분한다
    }
    int pos = p + f;
    vector<P> dp[(p + f) * 2];

    while (!pq.empty())
    {
        //만약 second가 1이면 소화전이므로 pos를 왼쪽으로 움직인 후 해당 인덱스에 pair를 넣어주고
        //만약 second가 0이면 해당 자리에 넣어주고 오른쪽으로 이동
        pq.top().second == 1 ? dp[--pos].push_back(pq.top()) : dp[pos++].push_back(pq.top());
        pq.pop();
    }

    for (int i = 0; i < (p + f) * 2; i++)
    {
        int s = 0, m;
        //(j가 홀수 일 때 소방차 좌표,소화전이 짝수, 이유는 소화전이 앞이니깐)
        for (int j = 1; j < dp[i].size(); j += 2)
            s += dp[i][j].first - dp[i][j - 1].first; //소방차좌표 - 소화전 좌표
        // s는 첫번 째 최솟값 검증
        m = s;
        if (dp[i].size() % 2 != 0) //만약 해당 i 번째 dp가 사이즈가 0이 아니면 소방차와 소화전 쌍이 맞지 않으므로
        {
            //두번 째 검증 필요
            for (int j = dp[i].size() - 1; j > 1; j -= 2) //뒤 부터 시작함
            {
                // dp[i][j]=뒤에 있는 소화전 ex) 5
                // dp[i][j-1]=가운데 소방차 ex) 4
                // dp[i][j-2]=앞에 있는 소화전 ex) 1
                //     (5-4) - (4-1) =  5  -(4*2) +1
                m = min(m, s += dp[i][j].first - dp[i][j - 1].first * 2 + dp[i][j - 2].first);
            }
        }
        ans += m;
    }

    cout << ans;
}
