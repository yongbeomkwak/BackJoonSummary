#include <bits/stdc++.h>

using namespace std;

#define MAX 200001
#define endl "\n"
#define tab " "

long long arr[MAX];
int n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    int lo = 0;          //최소거리
    int hi = arr[n - 1]; //가장 큰 값(끝값 - 0) //최대거리

    while (lo <= hi) //이분 탐색
    {
        const int mid = (lo + hi) / 2;
        int cnt = 1;       //가장 처음
        int prev = arr[0]; // 이전 좌표
        for (int i = 1; i < n; i++)
        {
            if (prev + mid <= arr[i]) //이전좌표 + 거리 <= 현재좌표
            {
                prev = arr[i]; //이전좌표 이동
                cnt++;         // 공유기 설치
            }
        }

        if (cnt >= m) //공유기 갯수가 주어진 개수 보다 크거나 같으면
        {
            ans = mid;
            lo = mid + 1; //쵯소값을 이동하여 거리 값을 늘림(공유기 설치 갯수를 줄이기 위해)
        }
        else
            hi = mid - 1; //아닐 경우 거리를 줄여 공유기 개수를 늘리게 한다.
    }

    cout << ans;
}
