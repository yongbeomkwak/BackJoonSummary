#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 500001
typedef pair<int, int> pai;
typedef vector<int>::iterator iter;

int max(const int &a, const int &b)
{
    return a > b ? a : b;
}
int min(const int &a, const int &b)
{
    return a < b ? a : b;
}

typedef struct _POST
{
    int s, e, m;
} Post;
int capacity[2001];
Post arr[10001];
bool comp(const Post &a, const Post &b)
{
    // E로 오름차순 정렬
    if (a.e == b.e)
    {
        return a.s < b.s; // S로 오름차순 정렬
    }
    return a.e < b.e;
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N = 0, C = 0, M = 0, ans = 0;
    cin >> N >> C;
    cin >> M;

    for (int i = 0; i < M; i++)
    {
        Post p;
        cin >> p.s >> p.e >> p.m;
        arr[i] = p;
    }
    sort(arr, arr + M, comp);

    for (int i = 0; i < M; i++)
    {
        int boxCnt = 0;
        for (int j = arr[i].s; j < arr[i].e; j++)
        {
            boxCnt = max(boxCnt, capacity[j]); //해당 범위에서 박스를 가장 많이 적재한 박스 갯수 찾기
        }

        int leftSpace = min(arr[i].m, C - boxCnt); // 현재 적재할 양과, C-boxCnt(현재 남은 공간) 비교 하여, 작은값 사용
        ans += leftSpace;                          // 적재
        for (int j = arr[i].s; j < arr[i].e; j++)
        {
            capacity[j] += leftSpace; //위에서 적재 했으므로 적재량 증가
        }
    }
    cout << ans;
}
