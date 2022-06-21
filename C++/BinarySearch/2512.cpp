#include <bits/stdc++.h>

using namespace std;

#define MAX 10001
#define endl "\n"
#define tab " "

int arr[MAX];
int n;
long long m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int lo = 0;
    int hi = arr[n - 1];
    int ans = 0;
    cin >> m;
    while (lo <= hi)
    {
        long long total = 0;
        int mid = (lo + hi) / 2;

        for (int i = 0; i < n; i++)
        {
            if (mid > arr[i])
                total += arr[i];
            else
                total += mid;
        }

        if (m < total)
            hi = mid - 1;
        else
        {
            ans = mid;
            lo = mid + 1;
        }
    }
    cout << ans;
}
