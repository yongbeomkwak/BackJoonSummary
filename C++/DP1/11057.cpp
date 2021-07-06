#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 1001
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
int N, T;
int DP[MAX][10];
int main()
{

    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    int ans = 0;
    for (size_t i = 0; i <= 9; i++) // DP[i][j]== 길이가 i 이며 j로 시작할 때 가능한 오름막 수
    {
        DP[1][i] = 1; //길이가 1이며 i로 시작할 때 가능한 오르막수 개수
    }

    //1은 위에서 했으므로
    for (size_t i = 2; i <= T; i++)
    {
        for (size_t j = 0; j <= 9; j++)
        {
            for (size_t k = j; k <= 9; k++)
            {
                /*
                자릿수가 올라갈수록 DP[i][j] = DP[i-1][0~j]를 누적하여 더해준다. 
                즉 수의 길이가 2고 앞자리가 1이라면 수의 길이가 1이고 앞자리수 j~9(오름차 순 j-1은 안됨)까지의 모든 경우를 더한 값이다.
                */
                DP[i][j] = (DP[i][j] + DP[i - 1][k]) % 10007; //
            }
        }
    }
    for (int i = 0; i < 10; i++)
    {
        ans = (ans + DP[T][i]) % 10007;
    }
    cout << ans;
}
