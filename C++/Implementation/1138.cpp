#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define tab " "
#define MAX 11
#define P pair<int, int>

int arr[MAX] = {
    0,
};
int pos[MAX] = {
    0,
};

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++)
    {
        int curr = arr[i] + 1; // 자기보다 큰 수 갯수 +1 을 시작 지점

        while (curr <= n) // n까지
        {
            int cnt = 0;
            for (int j = 1; j < curr; j++) // 1 부터 현재 위치 전까지
            {
                if (pos[j] == 0 || pos[j] > i)
                    cnt++; // 0(아직 안채워짐) 또는 큰 수가 있으면 카운팅
                if (cnt == arr[i])
                    break; //자리 찾았으면 종료
            }

            if (pos[curr] || cnt != arr[i]) //만약 비어있지 않거나 카운팅 개수가 틀리면 현재 위치 옮김
            {
                curr++;
                continue;
            }
            else
            {
                pos[curr] = i; //찾았으면 현재위치에 해당 사람 키 넣음
                break;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << pos[i] << tab;
    }
}
