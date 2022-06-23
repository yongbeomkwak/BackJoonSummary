#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define tab " "
#define MAX 501
#define P pair<int, int>
int h, w;
int _rains[MAX];
int _walls[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> h >> w;
    int answer = 0;
    for (int i = 1; i <= w; i++)
    {
        cin >> _walls[i];
    }
    int r, l;
    for (int i = 2; i < w; i++)
    {
        r = l = _walls[i];

        for (int j = 0; j < i; j++)
            l = max(_walls[j], l);
        for (int j = i + 1; j <= w; j++)
            r = max(_walls[j], r);

        answer += min(r, l) - _walls[i];
    }

    cout << answer;

    return 0;
}
