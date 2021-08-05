#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
#define MAX 1000001
#define endl "\n"
#define tab " "
#define MOD 1000000009
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
int dp[MAX];
int before[MAX];
int chartoi(const char &a)
{
    return (a - '0');
}

int BFS(const int &N)
{
    dp[1] = 0;
    for (int i = 2; i <= N; i++)
    {
        dp[i] = dp[i - 1] + 1;
        before[i] = i - 1;
        //3번 연산: i-1에 1을 더해 i 만드는 연산 , i에서 1을 빼서 i-1 만들 수 있는 경우의 수

        if (i % 3 == 0) // 3 나누기 연산이 가능할 때 ,1번 연산
        {
            if (dp[i] > dp[i / 3] + 1) //최솟값
            {
                dp[i] = dp[i / 3] + 1;
                before[i] = i / 3;
            }
        }

        if (i % 2 == 0) // 2 나누기 연산이 가능할 때 ,2번 연산
        {
            if (dp[i] > dp[i / 2] + 1) //최솟값
            {
                dp[i] = dp[i / 2] + 1;
                before[i] = i / 2;
            }
        }
    }
    return dp[N];
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //dp[i]=i까지 오는 최소 연산 , 역으로 하면 i부터 1까지 만들 수 있는 최소 역순이라 생각 할 수 있음
    //before[i]=i가 되기전, 상태
    cin >> n;
    cout << BFS(n) << endl;

    while (true)
    {
        cout << n << tab;
        n = before[n]; //n이 되기전 값을 n에 넣음
        if (n == 0)
        {
            break;
        }
    }
}
