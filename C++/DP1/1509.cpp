#include <bits/stdc++.h>

using namespace std;

#define MAX 2501
#define INF 987654321

int n;

bool dp[MAX][MAX];
int result[MAX];

int main()
{
    string tmp = " ", in;
    cin >> in;
    tmp += in;
    // tmp 제일 앞(0)은 쓰지 않을꺼이기 때문에 ! 해놓고, 입력을 뒤어 더해줌

    for (int i = 1; i < tmp.size(); i++)
    {
        dp[i][i] = true; //길이 i~i까지(길이 0) 회문 맞음
    }

    for (int i = 1; i < tmp.size(); i++)
    {
        if (tmp[i] == tmp[i + 1]) //다음께 같으면 i~i+1(길이1) 회문 맞음
        {
            dp[i][i + 1] = true;
        }
    }

    for (int i = 2; i < tmp.size(); i++)         //길이는 2부터 (길이 0부터 1까지 위에서 처리)
        for (int j = 1; j < tmp.size() - i; j++) //시작인덱스 1
        {
            if (tmp[j] == tmp[j + i] && dp[j + 1][i + j - 1]) //끝이 같고, 사이가 true면 회문
            {
                dp[j][j + i] = true;
            }
        }

    result[0] = 0;

    for (int i = 1; i < tmp.size(); i++)
    {
        result[i] = INF;
        for (int j = 1; j <= i; j++)
            if (dp[j][i])
                result[i] = min(result[i], result[j - 1] + 1);
    }

    cout << result[tmp.size() - 1];
}
