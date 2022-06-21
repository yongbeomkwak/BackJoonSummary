#include <bits/stdc++.h>

using namespace std;

#define MAX 100001
#define endl "\n"

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n;
    vector<int> arr;
    for (int i = 1; i <= n; i++)
    {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }

    sort(arr.begin(), arr.end());

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k;

        const int res = *lower_bound(arr.begin(), arr.end(), k);
        if (lower_bound(arr.begin(), arr.end(), k) - arr.begin() == n)
        {
            cout << 0 << endl;
            continue;
        }
        if (res == k)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
}
