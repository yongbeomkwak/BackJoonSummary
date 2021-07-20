#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 5001
#define endl "\n"
#define tab " "
#define MOD 9901
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

char input[MAX];
int code[MAX];
int n;
int dp[MAX];

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> input;

    dp[0] = 1; //일단 첫 문자는 한개 가능
    //dp[i] = i까지 만든 조합 수

    //dp[n]= dp[n]+dp[n-1]; -> 한 자리씩 해석한 문자 개수
    //dp[n]= dp[n]+dp[n-2]; -> 두 자리씩 해석한 문자 개수
    size_t len = strlen(input);
    for (int i = 1; i <= len; i++)
    {
        code[i] = input[i - 1] - '0'; //인덱스를 1부터 사용하기 위해 미룸
    }

    for (int i = 1; i <= len; i++)
    {
        if (code[i] != 0)
        {
            dp[i] = (dp[i - 1] + dp[i]) % 1000000;
        }

        int x = code[i] + code[i - 1] * 10;

        if (10 <= x && x <= 26)
        {
            dp[i] = (dp[i - 2] + dp[i]) % 1000000;
        }
    }
    cout << dp[len] % 1000000;
}
