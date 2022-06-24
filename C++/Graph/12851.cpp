#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define tab " "
#define MAX 100500
#define P pair<int, int>

bool isviist[MAX] = {
    false,
};
int ways[MAX] = {
    0,
};

int n, k;
int ans = INT_MAX;

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    cin >> n >> k;

    queue<P> q;

    q.push({0, n});

    while (!q.empty())
    {
        P now = q.front();
        int curr = q.front().second;
        int cnt = q.front().first;
        q.pop();

        if (curr == k)
        {
            ways[cnt]++;
            ans = min(ans, cnt);
        }

        isviist[curr] = true;

        if (curr - 1 >= 0 && !isviist[curr - 1])
            q.push({cnt + 1, curr - 1});
        if (curr + 1 <= MAX && !isviist[curr + 1])
            q.push({cnt + 1, curr + 1});
        if (curr * 2 <= MAX && !isviist[curr * 2])
            q.push({cnt + 1, curr * 2});
    }

    cout << ans << endl
         << ways[ans];
}
