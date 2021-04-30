#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(const int &a, const int &b) // 오름차순 
{
    if (a < b)
    {
        return true;
    }
    return false;
}
int main()
{
    vector<int> v1;
    int tc = 0;
    scanf("%d", &tc);
    for (int i = 0; i < tc; i++)
    {
        int temp = 0;
        scanf("%d", &temp);
        v1.push_back(temp);
    }
    sort(v1.begin(), v1.end(), comp); //(시작,끝,정렬함수)
    for (int i = 0; i < tc; i++)
    {
        cout << v1[i] << endl;
    }
}