#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define tab " "
#define MAX 205
#define P pair<int, int>

int r, c, n;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

typedef struct _BOMB
{
    int y, x;
} bomb;
vector<string> _map;
vector<string> after_expo;
vector<string> after_expo2;
vector<string> _full;
vector<bomb> bombs;

void explo() //첫번 째 폭발
{

    for (bomb &b : bombs)
    {
        int y = b.y;
        int x = b.x;
        after_expo[y][x] = '.';
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (nx < 0 || ny < 0 || ny >= r || nx >= c)
                continue;
            after_expo[ny][nx] = '.';
        }
    }
}

void explo2()
{

    for (bomb &b : bombs)
    {
        int y = b.y;
        int x = b.x;
        after_expo2[y][x] = '.';
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (nx < 0 || ny < 0 || ny >= r || nx >= c)
                continue;
            after_expo2[ny][nx] = '.';
        }
    }
}

void show(vector<string> &v)
{
    for (string &s : v)
    {
        cout << s << endl;
    }
}
int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    cin >> r >> c >> n;

    for (int i = 0; i < r; i++)
    {
        string s;
        cin >> s;
        _map.push_back(s);
        for (int j = 0; j < s.length(); j++)
        {
            if (s[j] == 'O')
                bombs.push_back({i, j}); //첫 번째 폭탄 들
        }
        after_expo.push_back(string(c, 'O'));
        _full.push_back(string(c, 'O'));
    }
    explo();
    bombs.clear();
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (after_expo[i][j] == 'O')
            {
                bombs.push_back({i, j});
            }
        }
    }
    after_expo2 = _full //두번 째 폭발을 위해 꽉 채운 후
    explo2();           //두번 째 폭발

    if (n <= 1)
        show(_map); // 1이하이면 그대로

    else if (n == 2)
        show(_full); // 2면 꽉

    else if (n == 3)
        show(after_expo); // 3번째면 첫번 째 폭발

    else if (n % 4 == 0 || n % 4 == 2)
        show(_full); //만약 0 또는 2면 꽉

    else if (n % 4 == 1)
        show(after_expo2); // 나머지 1이면 두번째 폭발

    else
        show(after_expo); //나머지는 첫번째 폭발
}
