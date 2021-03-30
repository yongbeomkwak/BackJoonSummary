#include <iostream>
#include <cstdio>
#include <array>
#include <algorithm>
#include <vector>
#include <cmath>

bool rightTriangle(int *const arr)
{
    if (arr[0] + arr[1] > arr[2])
    {
        if ((pow(arr[0], 2) + pow(arr[1], 2)) == pow(arr[2], 2))
        {
            return true;
        }
        return false;
    }
    return false;
}
using namespace std;
int main()
{

    while (1)
    {
        int arr[3] = {0};
        scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
        sort(arr, arr + 3);
        if (!(arr[0] && arr[1] && arr[2])) // 모두 0이면 break
        {
            break;
        }
        else
        {
            printf(rightTriangle(arr) ? "right\n" : "wrong\n");
        }
    }
}