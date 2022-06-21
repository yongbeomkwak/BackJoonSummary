#include <bits/stdc++.h>

using namespace std;

#define MAX 100001
#define endl "\n"
#define tab " "
vector<int> arr;
unordered_map<int, int> um;

int bs(const int k)
{
    int lo = 0;
    int hi = arr.size() - 1;
    int idx = -1;
    int ret = 0;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        // cout<< k << " "<< lo << " " << mid << " " << hi <<endl;
        if (arr[mid] == k)
        {
            idx = mid;
            break;
        }
        if (arr[mid] > k)
            hi = mid - 1;
        else
            lo = mid + 1;
    }
    for (int i = idx - um[k]; i <= idx + um[k]; i++)
    {

        if (i < 0 || i >= arr.size())
            continue;
        if (arr[i] == k)
            ret++;
    }
    return ret;
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
        um[tmp]++;
    }

    sort(arr.begin(), arr.end());
    cin >> m;

    /*
    lower_bound(~,~,4)의 결과 : 3 (4 이상의 값이 처음 나타나는 위치)
    upper_bound(~,~,4)의 결과 : 5 (4를 초과하는 값이 처음 나타나는 위치)를 이용해서
    */

    for (int i = 0; i < m; i++)
    {
        int card;
        cin >> card;
        cout << upper_bound(arr.begin(), arr.end(), card) - lower_bound(arr.begin(), arr.end(), card) << tab;
    }
}
