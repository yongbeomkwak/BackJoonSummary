#include <bits/stdc++.h>

using namespace std;




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<string> ret;
    string in;
    cin >> in;

    while (!in.empty())
    {
        ret.push_back(in);
        in.erase(in.begin());
    }
    sort(ret.begin(), ret.end());

    for (const string &s : ret)
    {
        cout << s << endl;
    }
}
