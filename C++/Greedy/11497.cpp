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
int T = 0;

int max(const int &a, const int &b)
{
    return a > b ? a : b;
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int N;
        cin >> N;
        int arr[10001] = {0};
        int ans = 0;
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + N);
        //정렬 한 후

        /*
        2, 4, 5, 7, 9
        2, 5, 9, 7, 4
        왼쪽에 제일 작은수 하나, 오른쪽에 그 다음 작은수 하나
        2
        2           4
        2,5         ,4
        2,5        7,4
        2,5  ,9,7.4
        
        오름 차순 정렬 기준 
        2 4 5 7 9 
        높이 차이 최대 값은  현재 인덱스 기준 -2 만큼 차이 난다
        이유 정렬 기준 가장 높이 차이가 최소인 값은 오른쪽 끝으로 보내 지고
        2 4 ->   2  ..... 4
        그 다음 최소는 자기 옆으로옴
        2  5 ...... 4 (여기서 i와 i-2) 2의 차이가 발생 됨 이렇게 모든 상황에 대하여  2번 째 최소로 모두 맞춰 값을 넣으면, 모든 경우가 최소가 되고,그 안에서 최대값을 구하면됨
        */
        for (int i = 2; i < N; i++)
        {
            ans = max(ans, arr[i] - arr[i - 2]); // i 기준 i-1(바로 왼쪽은) 항상 최소 값이고,i-2 값이 최대값
        }
        cout << ans << "\n";
    }
}
