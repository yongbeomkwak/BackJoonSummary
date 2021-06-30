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
char input[MAX];
int N = 0;

bool comp(const int &a, const int &b)
{
    return a > b;
}
int min(const int &a, const int &b)
{
    return a < b ? a : b;
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int K = 0;
    int arr[1000001] = {0};
    int dist[1000001] = {0};
    cin >> N;
    cin >> K;
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + N);

    for (int i = 0; i < N - 1; i++)
    {
        dist[i] = arr[i + 1] - arr[i]; //인접한 지점 끼리 거리 계산
    }
    sort(dist, dist + N, comp); //내림 차순 정렬

    for (int i = 0; i < K - 1; i++) //거리 차이가 큰 순서 부터 ,K-1 개 만큼 벽을 설치한다  즉 K=2 면 , 1 개 만큼 벽을 설치하면(dist[i]=0) 2개의 구간으로 구분된다
    {
        dist[i] = 0;
    }

    for (int i = 0; i < N; i++)
    {
        ans += dist[i];
    }
    cout << ans;
}
