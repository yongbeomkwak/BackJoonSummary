#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 2001
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

int n, m, s, e;
int dp[MAX][MAX];
int arr[MAX];

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    //dp[s][e] == s~e 까지 Palindrome
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        dp[i][i] = 1; // 길이가 1일 경우 Palindrome
    }
    for (int i = 2; i <= n; i++)
    {
        //길이가 2일 때 (i 와 i-1) 양 끝이 같으면 Palindrome
        if (arr[i] == arr[i - 1]) // i=2일 때   arr[1]==arr[2]
        {
            dp[i - 1][i] = 1; // dp[1][2]  ->1  부터 2까지는 Palindrome , n-1 부터 n까지
        }
    }

    //길이 1 과 2일 경우 해결
    //양 끝이 같고  그 사이 값이 Palindrome이면 그 수는 Palindrome
    for (int i = 2; i <= n; i++)
    {
        // 1~3
        for (int j = 1; j <= n; j++)
        {
            // 1 ~3 부터 시작  j=1,i=2
            //arr[j],arr[j+i] , 양 끝 값  , j+1 ~ j+i-1, 사이값
            if (arr[j] == arr[j + i] && dp[j + 1][j + i - 1]) // 모두 만족하면
            {
                dp[j][j + i] = 1; //Palindrome
            }
        }
    }

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> s >> e;
        cout << dp[s][e] << endl;
    }
}
