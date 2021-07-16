#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 10001
#define endl "\n"
#define tab " "
#define MOD 9901
typedef pair<int, int> pai;
typedef vector<int>::iterator iter;
typedef unsigned long long ull;

int max(const int &a, const int &b)
{
    return a > b ? a : b;
}

int min(const int &a, const int &b)
{
    return a < b ? a : b;
}

bool comp(const int &a, const int &b)
{
    return a > b;
}

int n;
int dp_max[3];
int dp_min[3];
int arr[MAX][MAX];
int sum[MAX];

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    //초기화
    cin >> dp_max[0] >> dp_max[1] >> dp_max[2];
    dp_min[0] = dp_max[0];
    dp_min[1] = dp_max[1];
    dp_min[2] = dp_max[2];
    int input[3] = {0, 0, 0};
    int temp0, temp1;

    //위에서 한 줄 입력 받았으므로  i=1부터 시작
    for (int i = 1; i < n; i++)
    {
        cin >> input[0] >> input[1] >> input[2];
        temp0 = dp_max[0];
        temp1 = dp_max[1];
        dp_max[0] = max(dp_max[0], dp_max[1]) + input[0];
        dp_max[1] = max(temp0, max(dp_max[1], dp_max[2])) + input[1];
        dp_max[2] = max(temp1, dp_max[2]) + input[2];
        temp0 = dp_min[0];
        temp1 = dp_min[1];
        dp_min[0] = min(dp_min[0], dp_min[1]) + input[0];
        dp_min[1] = min(temp0, min(dp_min[1], dp_min[2])) + input[1];
        dp_min[2] = min(temp1, dp_min[2]) + input[2];
    }
    cout << max(dp_max[0], max(dp_max[1], dp_max[2])) << tab << min(dp_min[0], min(dp_min[1], dp_min[2])) << endl;
}
