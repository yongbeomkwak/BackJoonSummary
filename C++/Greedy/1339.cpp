#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool compare(string &a, string &b)
{
    return a.size() > b.size() ? true : false;
}

bool comp(int &a, int &b)
{
    return a > b ? true : false;
}

vector<string> v;
vector<int> num(26);
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N = 0;
    string a;
    cin >> N;
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        string prev;
        cin >> prev;
        v.push_back(prev);
    }
    sort(v.begin(), v.end(), compare);
    for (string &s : v)
    {
        int size = pow(10, s.size() - 1);
        for (char &c : s)
        {
            num[int(c) - 65] += size;
            size /= 10;
        }
    }
    sort(num.begin(), num.end(), comp);
    int re_num = 9;
    for (int i = 0; i < 26; i++)
    {
        if (num[i] == 0)
            break;
        sum += num[i] * re_num;
        re_num--;
    }
    cout << sum << "\n";
}
