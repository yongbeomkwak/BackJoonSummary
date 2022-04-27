#include <bits/stdc++.h>

using namespace std;

#define MAX 31

int n, w;

long long dp[MAX][MAX]; // dp[whole][half] = 1개짜리가 whole개이고 반개짜리가 half일 때

long long solve(const int whole, const int half)
{
    if (whole == 0)
        return 1; // 1개 짜리가 없다는 것은 , 반개 뿐이니 경우의 수 1개

    long long &ret = dp[whole][half]; //래퍼런스 사용
    if (ret != 0)
        return ret; //이미 값 존재하면 그대로 리짜리가

    ret = solve(whole - 1, half + 1); // 1개짜리 쪼갠 후 반개는 먹고, 반개는 병에 담는다.

    if (half > 0) //만약 반개짜리 존존재하면
    {
        ret += solve(whole, half - 1); //반개 짜리 먹은 경우의 수
    }

    return ret;
}

int main()
{
    string tmp;

    for (int i = 1; i <= 30; i++)
    {
        solve(i, 0); // 1개부터 ~30개 까지 모두 돌림
    }

    while (getline(cin, tmp))
    {
        if (tmp == "0")
            break;
        long long &ret = dp[stoi(tmp)][0]; // tmp->int로 , dp[N개][0개]
        cout << ret << endl;
    }
}
