#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 1001
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
int n, m;
int dp[MAX][MAX];
int arr[MAX][MAX];

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        string a;
        cin >> a;
        for (int j = 0; j < a.size(); j++)
        {
            arr[i][j + 1] = a[j] - '0'; //j를 1부터 사용하기 위해
        }
    }

    int Max_Len = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (arr[i][j] != 0) //만약 현재 위치가 0이 아닐 경우  , 현재위치를 사각형의 가장 오른쪽 아래로 본다
            {
                //정사각형인지 판단
                arr[i][j] = min(arr[i - 1][j - 1], min(arr[i - 1][j], arr[i][j - 1])) + 1; // 그때 i-1 j-1(왼쪼 위 대각선), i-1(위),(j-1) 왼쪽 이를 볼 때 가장 작은 값을 찾은 후 +1
                if (Max_Len < arr[i][j])                                                   //최대 길이 찾기
                    Max_Len = arr[i][j];
            }
        }
    }
    cout << Max_Len * Max_Len << endl; //최대길이^2
}
