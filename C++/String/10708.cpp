#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int max_len = 0;
    vector<string> v;
    for (int i = 0; i < 5; i++)
    {
        string tmp;
        cin >> tmp;
        max_len = tmp.length() > max_len ? tmp.length() : max_len; //문자열 중 가장 긴 길이
        v.push_back(tmp);
    }
    string ret;
    for (int i = 1; i <= max_len; i++) // 1~ 맥시멈 길이까지
    {
        for (int j = 0; j < 5; j++)
        {
            if (i > v[j].length())
                continue; //현재 목표 길이보다 현재 길이 문자열 길이가 짧으면 추가 불가
            ret += v[j][i - 1];
        }
    }
    cout << ret;
}
