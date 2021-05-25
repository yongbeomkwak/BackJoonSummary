#include <iostream>

using namespace std;

int main()
{
    int n, re, temp1;
    int temp2 = 0;

    cin >> n;
    cin >> re;
    int *a = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = (n - 1); i >= 0; i--)
    {
        if (a[i] <= re)
        {
            temp1 = re / a[i];
            temp2 += temp1;
            re = re % a[i];
        }
        else
        {
            continue;
        }
    }

    cout << temp2;
}