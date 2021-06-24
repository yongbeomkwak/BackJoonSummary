#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define LMIT 1000001

bool comp(char a, char b)
{
    return int(a) == int(b) ? true : false;
}
int min(int &a, int &b)
{
    return a < b ? a : b;
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    char input[LMIT];
    cin >> input;
    int count_1 = 0;
    int count_0 = 0;
    int answer = 0;
    if (comp(input[0], '1')) //첫번 째 글자에 대하여 카운트 증가
    {
        count_1++;
    }
    else
    {
        count_0++;
    }
    for (int i = 1; i < strlen(input); i++)
    {
        if (!comp(input[i], input[i - 1])) // 앞에 글자와 다르다 는 뜻, 연속하지 않다
        {
            if (comp(input[i], '0'))
            {
                count_0++;
            }
            else
            {
                count_1++;
            }
        }
    }
    cout << min(count_0, count_1); //작은거 츨력
}
