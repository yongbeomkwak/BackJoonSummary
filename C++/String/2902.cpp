#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string in;
    cin >> in;
    string ret;
    bool get_flag = true;
    for (const char &c : in)
    {
        if (get_flag)
        {
            ret += c;
            get_flag = false;
        }
        if (!isalpha(c))
        {
            get_flag = true;
        }
    }
    cout << ret;
}
