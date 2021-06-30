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

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N = 0;
    int high[30001];
    int ans = 0;
    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> high[i];
    }

    for (int start = 0; start < N; start++)
    {
        int temp = 0;

        for (int i = start + 1; i < N; i++)
        {
            if (high[start] >= high[i])
            {
                temp++;
            }
            else
            {
                break;
            }
        }
        ans = max(ans, temp);
        }

    cout << ans;
}
