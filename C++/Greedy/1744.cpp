#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool comp(const int &a, const int &b)
{
    return abs(a) < abs(b);
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> v1;
    vector<int> v2;
    int N = 0;
    int result = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int temp = 0;
        cin >> temp;
        if (temp > 0)
        {
            v1.push_back(temp);
        }
        else
        {
            v2.push_back(temp);
        }
    }
    sort(v1.begin(), v1.end(), comp);
    sort(v2.begin(), v2.end(), comp);
    while (v1.size() > 1)
    {
        int temp1 = v1[v1.size() - 1];
        v1.pop_back();
        int temp2 = v1[v1.size() - 1];
        v1.pop_back();
        if (temp1 != 1 && temp2 != 1)
        {
            result += (temp1 * temp2);
        }
        else
        {
            result += (temp1 + temp2);
        }
        }
    if (v1.size() == 1)
    {
        result += v1[0];
    }
    while (v2.size() > 1)
    {
        int temp1 = v2[v2.size() - 1];
        v2.pop_back();
        int temp2 = v2[v2.size() - 1];
        v2.pop_back();
        if (temp1 * temp2 >= 0)
        {
            result += (temp1 * temp2);
        }
        else
        {
            result += (temp1 + temp2);
        }
    }
    if (v2.size() == 1)
    {
        result += v2[0];
    }
    cout << result << "\n";
}
