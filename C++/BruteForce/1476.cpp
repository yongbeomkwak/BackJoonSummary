#include <bits/stdc++.h>

using namespace std;
#define MAX 101

// (1 ≤ E ≤ 15, 1 ≤ S ≤ 28, 1 ≤ M ≤ 19)

int e, s, m;
int ans;
void calc(const int cnt, const int _e, const int _s, const int _m)
{
    if (e == _e && s == _s && m == _m)
    {
        ans = cnt;
        return;
    }

    int ne = (_e + 1) > 15 ? 1 : _e + 1;
    int ns = (_s + 1) > 28 ? 1 : _s + 1;
    int nm = (_m + 1) > 19 ? 1 : _m + 1;
    calc(cnt + 1, ne, ns, nm);
    return;
}

int main()
{
    cin >> e >> s >> m;

    calc(1, 1, 1, 1);
    cout << ans;
}
