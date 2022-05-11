#include <bits/stdc++.h>

using namespace std;
#define MAX 51

char arr[MAX][MAX];

unordered_map<string, int> um;

bool selected[MAX][MAX];
int ans = 0;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

void dfs(const int x, const int y, string s)
{
    if (s.length() == 6) // 6자리면 확인
    {
        if (um[s] == 0) //만약 이전에 입력된 적이 없으면
        {
            ans++;     //증가
            um[s] = 1; //입력
        }
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        const int nx = x + dx[i];
        const int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5)
            continue;     //범위 검사
        s += arr[nx][ny]; //새 문자 더한후
        dfs(nx, ny, s);   // dfs
        s.pop_back();     // 뒷문자 빼기
    }
}

int main()
{

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            dfs(i, j, ""); //모든 범위에서 출발해봄
        }
    }

    cout << ans;
}
