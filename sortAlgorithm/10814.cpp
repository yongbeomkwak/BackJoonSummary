#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

bool comp(const pair<int, string> &a, const pair<int, string> &b)
{
    //pair 객체를 받아
    if (a.first < b.first) //first 오름차순
    {
        return true;
    }

    return false;
}

int main()
{
    int tc = 0;
    vector<pair<int, string> > v; //pair 객체로 저장
    int a = 0;
    string b;
    scanf("%d", &tc);
    for (int i = 0; i < tc; i++)
    {
        cin >> a >> b;
        pair<int, string> p(a, b);
        v.push_back(p);
    }
    stable_sort(v.begin(), v.end(), comp); //같은 값일 때 순서를 바꾸지 않기위해서 

    for (auto k = v.begin(); k != v.end(); k++)
    {
        cout << k->first << " " << k->second << '\n';
    }
}