#include <bits/stdc++.h>

using namespace std;

#define FAULT "FRULA"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s, bomb;
    cin >> s;
    cin >> bomb;
    vector<char> v;
    const int len = bomb.length();

    for (int i = 0; i < s.length(); i++)
    {
        v.push_back(s[i]);

        if (v.size() >= bomb.length())
        {
            bool explo = true;
            for (int j = 0; j < bomb.size(); j++)
            {
                if (v[v.size() - bomb.size() + j] != bomb[j]) // v 뒤에서 bomb의 길이만큼 검사
                {
                    explo = false;
                    break;
                }
            }

            if (explo) //폭발 가능할 때
            {
                for (int i = 0; i < bomb.size(); i++)
                {
                    v.pop_back(); //폭발
                }
            }
        }
    }
    if (v.empty()) // 비었을 때;
    {
        cout << FAULT;
    }
    else
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i];
        }
    }
}
