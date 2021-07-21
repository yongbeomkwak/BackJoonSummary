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
string dp[MAX][MAX];

string bigNumAdd(string n1, string n2)
{
    int sum = 0;
    string result;
    // 1의 자리부터 더하기
    //더하는 이유:파스칼의 삼각형
    while (!n1.empty() || !n2.empty() || sum)
    {
        if (!n1.empty())
        {
            sum += n1.back() - '0';
            n1.pop_back();
        }
        if (!n2.empty())
        {
            sum += n2.back() - '0';
            n2.pop_back();
        }
        result.push_back((sum % 10) + '0');
        sum /= 10;
    }

    // 1의 자리부터 push 했으므로 뒤집어준다.
    reverse(result.begin(), result.end());
    return result;
}

string combination(const int &n, const int &r)
{
    if (n == r || r == 0)
        return "1";
    string &result = dp[n][r]; // 참조형 변수
    // 이미 계산했으면 바로 return, memoization 기법
    if (result != "")
        return result;

    // 파스칼삼각형 원리 이용   n C r =n-1 C r-1+ n-1 C r
    //      5C2 = 4C1 + 4 C 2 ,
    result = bigNumAdd(combination(n - 1, r - 1), combination(n - 1, r));
    return result;
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;

    cout << combination(n, m);
}
