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
#define MAX 10001
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
string dp[MAX];

int chartoi(const char &a)
{
    return (a - '0');
}

string append(string a, string b)
{
    int num = 0;   // 합 계산 후  넘어가지 않고 남은 수
    int carry = 0; //  다음 자릿 수로 넘어가는 수
    string res;
    //일의 자리 부터 계산 하기 위해  반전 하기
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    //적은 자릿 수 만큼 0을 앞에 뒤에 넣어 줌
    //ex) a=1234
    //ex) b=12
    //    b=2100(이렇게 됨 ) -> 0012
    while (a.length() < b.length())
    {
        a += '0';
    }
    while (b.length() < a.length())
    {
        b += '0';
    }

    for (int i = 0; i < a.length(); i++)
    {
        int x = chartoi(a[i]);
        int y = chartoi(b[i]);
        num = (x + y + carry) % 10;   //넘어오는 수(carry) 역시 계산 해주고
        res += to_string(num);        //먼저 num(나머지) 더해주고
        carry = (x + y + carry) / 10; //넘어가는 수 계산 해주고
    }

    if (carry)
    {
        //만약 마지막 carry가 남아 있다면
        res += to_string(carry);
    }

    reverse(res.begin(), res.end()); //  리턴하기 위한 뒤집기
    return res;
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    dp[0] = '0';
    dp[1] = '1';
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = append(dp[i - 1], dp[i - 2]); // fibo 계산 (a와 b 합치기)
    }
    cout << dp[n] << endl;
}
