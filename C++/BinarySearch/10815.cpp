#include <bits/stdc++.h>

using namespace std;

#define MAX 100001
#define endl "\n"
vector<int> arr;

bool bs(const int k)
{
    int lo = 0;
    int hi = arr.size() - 1;

    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        // cout<< k << " "<< lo << " " << mid << " " << hi <<endl;
        if (arr[mid] == k)
            return true;
        if (arr[mid] > k)
            hi = mid - 1;
        else
            lo = mid + 1;
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n;

    for (int i = 0; i < n; i++)
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

        if (bs(k))
            cout << 1 << " ";
        else
            cout << 0 << " ";
    }
}
