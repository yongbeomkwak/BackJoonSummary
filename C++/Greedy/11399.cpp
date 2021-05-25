#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N = 0;
    cin >> N;
    int *time = new int[N];
    int *min_wait = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> time[i];
    }

    sort(time, time + N);

    for (int i = 0; i < N; i++)
    {
        if (i == 0)
        {
            min_wait[0] = time[0];
        }

        else
        {
            min_wait[i] = time[i] + min_wait[i - 1];
        }
    }
    int result = 0;

    for (int i = 0; i < N; i++)
    {
        result += min_wait[i];
    }

    cout << result;

    delete[] time;
    delete[] min_wait;
}