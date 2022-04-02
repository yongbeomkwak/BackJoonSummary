#include <bits/stdc++.h>

using namespace std;

bool check_palindrome(const string &s)
{
    bool ret;
    if (s.length() % 2 == 0)
    {
        const int mid = s.length() / 2;
        string l = s.substr(0, mid);
        string r = s.substr(mid);
        reverse(r.begin(), r.end());
        if (!l.compare(r))
            ret = true;
        else
            ret = false;
    }
    else
    {
        const int mid = s.length() / 2;
        string l = s.substr(0, mid);
        string r = s.substr(mid + 1); //중간 건너 뛰고
        reverse(r.begin(), r.end());
        if (!l.compare(r))
            ret = true;
        else
            ret = false;
    }
    return ret;
}

int main()
{
    string str;

    while (getline(cin, str))
    {
        if (str == "0")
            break;

        check_palindrome(str) == true ? cout << "yes" : cout << "no";
        cout << endl;
    }
}
