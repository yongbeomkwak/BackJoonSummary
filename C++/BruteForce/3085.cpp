#include <bits/stdc++.h>

using namespace std;

#define MAX 51
#define endl "\n"
#define tab " "

char arr[MAX][MAX];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n;
int inspection(const int r, const int c)
{
    int cnt = 1;
    int ret = 0;

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[r][i] != arr[r][i + 1])
            cnt = 1;
        else
            cnt++;
        ret = max(ret, cnt);
    }
    cnt = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i][c] != arr[i + 1][c])
            cnt = 1;
        else
            cnt++;
        ret = max(ret, cnt);
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int answer = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        answer = max(inspection(i, 0), answer);
        answer = max(inspection(0, i), answer);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                int ny = i + dy[k];
                int nx = j + dx[k];
                if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                    continue;
                if (arr[i][j] == arr[ny][nx])
                    continue;
                char tmp = arr[i][j];
                char tmp2 = arr[ny][nx];
                arr[i][j] = tmp2;
                arr[ny][nx] = tmp;
                answer = max(answer, inspection(i, j));
                arr[i][j] = tmp;
                arr[ny][nx] = tmp2;
            }
        }
    }

    cout << answer;
}
