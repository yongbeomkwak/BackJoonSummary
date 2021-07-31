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
#define MAX 45
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

int n, m;
int dp[MAX];
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    dp[0] = 1; // 이게 중요함 ...()
    dp[1] = 1;
    dp[2] = 2;
    //dp[i]= i개로 만들 수 있는 경우의 수(자리 바꿈 가능여부를 고려한)
    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2]; // 합 법칙 , dp[i-1] 자리 옮기지 않는 경우, dp[i-2] 자리 옮기는 경우
    }
    int ans = 1;
    int start = 0;
    for (int i = 0; i < m; i++)
    {
        int end = 0;
        cin >> end;
        ans *= dp[end - start - 1]; // 만약  m=2, end=4,7 일 때  end-start-1= 3(4-0-1) , 2(7-4-1) , 1 2 3(3) /4/    5  6(2) /7/    8 9(2)
        start = end;
    }
    //m=2면 3등 분 마지막 등분은 여기서 해줌
    ans *= dp[n - start]; // 9-7(8 9)=2
    cout << ans << endl;
}
