#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

void cal1(size_t &a)
{
    a /= 2;
}
void cal2(size_t &a)
{
    a -= 1;
    a /= 10;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N = 0;
    cin >> N;
    int arr[101];
    int answer = 0;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }

    for (int i = N; i >= 2; i--)
    {
        int temp1 = arr[i];
        int temp2 = arr[i - 1];
        if (temp1 <= temp2)
        {
            answer += (temp2 - (temp1 - 1));
            arr[i - 1] = temp1 - 1;
        }
    }
    cout << answer;
}
