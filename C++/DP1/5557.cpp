#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 101
#define endl "\n"
#define tab " "
#define MOD 9901
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
int cnt = 0;
int ans = 0;
int result = 0;
long dp[MAX][21];
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
    //DP[i][j] //i 번째 수 까지 연산 했을 때  j를 만들 수있는 개수

    dp[1][arr[1]]++;            // 1번 째 연산 결과는  배열의 첫번 째 수 증가
    for (int i = 2; i < n; i++) // n일 때는 항상 = 연산자를 사용할 것이므로
    {
        //dp[2][0] -> 2번 째 수까지 사용 했을때 0을 만들 수 있는 개수
        for (int j = 0; j < 21; j++)
        {
            if (dp[i - 1][j]) //만약 그 전 연산 결과가 j일 때  값이 0이 아니라면(즉 존재 한다면)
            {
                //다음 연산(+) 20 이하일 경우,
                if (j + arr[i] <= 20)
                    dp[i][j + arr[i]] += dp[i - 1][j];
                //다음 연산(-) 0 이상일 경우
                if (j - arr[i] >= 0)
                    dp[i][j - arr[i]] += dp[i - 1][j];
            }
        }
    }
    cout << dp[n - 1][arr[n]]; // 마지막 수를 제외한 모든 연산을 끝 맞췄을 때 마지막 숫자가 와 같은 총 개수 출력
}
