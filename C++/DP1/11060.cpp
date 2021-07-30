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
#define MAX 1001
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
int arr[MAX];
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    if (n == 1) // 목적지가 1이면 점프 횟수 0
    {
        cout << dp[1];
        return 0;
    }
    //dp[i]= i까지 도달 했을 때 최소 점프 횟수
    dp[1] = 0;
    for (int i = 1; i <= n; i++) // 1번 부터 시작
    {
        for (int j = 1; j <= arr[i]; j++) //1 부터 점프 가능한 거리까지 모두 순회
        {
            if (i != 1 && dp[i] == 0) //만약 위치 i 가 1이 아니고 dp[i]=0 이란 뜻은 과거의 점프들로 해당 위치를 도달하지 못했다는 뜻, 더 이상 방문 가치 없음
            {
                break;
            }
            if (i + j <= n) // 이제 현재위치(i)+j(점프 거리) = 이동할 위치가 (n) 보다 작을 때 (Index of Bound 방지)
            {
                if (!dp[i + j]) // 도착지가 0이란 뜻은 이전에 한번도 도착 안했음 , 즉 처음 도착했을 때
                {
                    dp[i + j] = dp[i] + 1; // 이전 점프횟수에 +1 함
                    continue;
                }
                dp[i + j] = min(dp[i + j], dp[i] + 1); // 만약 여기 왔다는 뜻은 그전에 최소 점프 횟수가 있고 , 현재 위치에서 +1 했던 덧과 비교
            }
            else
            {
                break;
            }
        }
    }

    dp[n] == 0 ? cout << -1 : cout << dp[n]; // 0이면 -1 오픈
}
