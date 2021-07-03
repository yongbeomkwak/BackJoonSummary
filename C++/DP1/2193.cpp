#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 500001
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
unsigned long long memo[91][2] = {0};
unsigned long long DP(int n)
{
    if (n <= 2) //2자리 까지는 여기서 리턴
    {
        return memo[n][0] + memo[n][1];
    }
    else
    {
        for (int i = 3; i <= n; i++) //3자리 부터
        {
            memo[i][0] = memo[i - 1][0] + memo[i - 1][1]; //현재 뒤에 0으로 끝나는 것은= 그전의 0으로 끝나는 것+ 그전에 1로 끝나는 것
            memo[i][1] = memo[i - 1][0];                  //현재 뒤에 1이 올 수 있는 경우는 그전에 0으로 끝나는 것만 가능
        }
        return memo[n][0] + memo[n][1];
    }
}

int main()
{

    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    memo[0][0] = 0;
    memo[1][1] = 1; // 1
    memo[2][0] = 1; //10
                    // 101 ,100 //
    // memo[4] = 3; //1010            1000        1001
    // memo[5] = 5; // 10101 10100 10001 10000    10010
    cout << DP(N);
}
