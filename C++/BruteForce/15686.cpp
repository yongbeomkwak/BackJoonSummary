#include <bits/stdc++.h>

using namespace std;
#define MAX 51

typedef struct _POINT
{
    int x, y;
} point;

int n, m;
int arr[MAX][MAX];
vector<point> homes;
vector<point> chicken;
vector<point> picked;
bool selected[MAX] = {
    false,
};
int ans = 987654321;
int calc_dist(point a, point b)
{
    return abs(a.x - b.x) + abs(a.y - b.y);
}

void calc_min_dist() //최소 값 구하기
{
    int ret = 0;
    for (int i = 0; i < homes.size(); i++) //모든 집
    {
        int _min = 987654321;
        for (int j = 0; j < picked.size(); j++) //선택한 모든 치킨 집
        {
            _min = min(_min, calc_dist(picked[j], homes[i]));
        }
        ret += _min; //해당 집에서 가장 가까운 치킨거리 더함
    }

    ans = min(ans, ret);
}

void find_M_comb(const int start, const int cnt)
{
    if (cnt == m) //모두 담았으니
    {
        calc_min_dist(); //도시 치킨 계산
    }

    for (int i = start; i < chicken.size(); i++)
    {
        if (selected[i])
            continue;

        picked.push_back(chicken[i]); //해당 치킨 집 담음
        selected[i] = true;
        find_M_comb(i, cnt + 1); //담았으니 재귀
        selected[i] = false;
        picked.pop_back(); //빼줌
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 1)
                homes.push_back({i, j});
            if (arr[i][j] == 2)
                chicken.push_back({i, j});
        }
    }

    find_M_comb(0, 0);

    cout << ans;
}
