
#include <bits/stdc++.h>

using namespace std;

#define MAX 1000001
#define endl "\n"
#define tab " "

int arr[MAX];
int n, m;
const long long sum(const int limit)
{
    int ret = 0;

    int start = upper_bound(arr, arr + n, limit) - arr;
    for (int i = start; i < n; i++)
    {
        ret += arr[i] - limit;
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int ans = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int lo = 0;
    int hi = arr[n - 1];

    while (lo <= hi)
    {
        const int mid = (hi + lo) / 2;

        long long _sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > mid)
                _sum += (arr[i] - mid);
        }
        if (_sum < m)
            hi = mid - 1;
        else
        {
            ans = max(ans, mid);
            lo = mid + 1;
        }
    }
    cout << ans;
}
