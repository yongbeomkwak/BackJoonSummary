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

int arr[MAX];
int n;
int dp[MAX];
vector<int> v[MAX];
vector<int> answer;

void print()
{
    cout << answer.size() << endl;
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << tab;
    }
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++)
    {
        dp[i] = 1;
        v[i].push_back(arr[i]); //자기 자신을 가장 먼저 넣은 뒤(가장 처음 요소를 넣어주기 위함, 이것을 안하면 앞에가 비워짐)
        for (int j = 1; j <= i; j++)
        {
            if (arr[i] > arr[j]) //증가 수열이 맞고
            {
                if (dp[i] < dp[j] + 1) // 과거에  가장 긴 수열+1 보다 작을 경우 새로 업데이트
                {
                    v[i].clear();           //만약 존재하면
                    v[i] = v[j];            //이전에 저장한 요소 들을 불러오고
                    v[i].push_back(arr[i]); //여기서 자기 자신을 넣어줌
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            if (answer.size() < v[i].size())
            {
                answer = v[i];
            }
        }
    }
    print();
}
