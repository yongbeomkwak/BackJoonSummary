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
    size_t A, B = 0;
    cin >> A >> B;
    bool find = false;
    int answer = 0;
    while (A <= B)
    {

        if (A == B)
        {
            find = true;
            break;
        }
        else
        {
            if (B % 10 == 1)
            {
                cal2(B);
                answer++;
            }
            else if (B % 2 == 0)
            {
                cal1(B);
                answer++;
            }
            else
            {
                break;
            }
        }
    }
    find == true ? cout << answer + 1 : cout << -1;
}
