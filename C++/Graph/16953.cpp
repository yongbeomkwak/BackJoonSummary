#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define tab " "
#define MAX 1000000001
#define P pair<int, long long>

long long mul2(const long long n)
{
    return 2 * n;
}

long long add1(const long long n)
{
    return n * 10 + 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long a, b;
    cin >> a >> b;

    queue<P> q;
    int cnt = INT_MAX;
    q.push({0, a});
    int ans = INT_MAX;

    while (!q.empty())
    {
        P now = q.front();
        q.pop();

        long long next1 = mul2(now.second);
        long long next2 = add1(now.second);

        if (next1 < b)
            q.push({now.first + 1, next1});
        else if (next1 == b)
            ans = min(ans, now.first + 1);

        if (next2 < b)
            q.push({now.first + 1, next2});
        else if (next2 == b)
            ans = min(ans, now.first + 1);
    }

    if (ans == INT_MAX)
        cout << -1;
    else
        cout << ans + 1;
}
