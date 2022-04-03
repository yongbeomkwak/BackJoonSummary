#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;

    cin >> tc;

    while (tc--)
    {
        deque<int> dq;
        bool error = false, reverse = false;
        string command, arr;
        int n;
        cin >> command;
        cin >> n;
        cin >> arr;

        string tmp = "";
        for (const char &c : arr)
        {
            if (isdigit(c))
                tmp += c;
            else
            {
                if (tmp.empty())
                    continue;
                dq.push_back(stoi(tmp));
                tmp.clear();
            }
        }

        for (const char &c : command)
        {
            if (c == 'R')
                reverse = !reverse;
            else
            {
                if (dq.size() == 0)
                {
                    error = true;
                    break;
                }

                if (reverse)
                    dq.pop_back();
                else
                    dq.pop_front();
            }
        }

        if (error)
            cout << "error" << endl;
        else
        {
            cout << "[";
            while (!dq.empty())
            {
                if (dq.size() == 1)
                {
                    cout << dq.front();
                    dq.pop_front();
                }

                else
                {
                    if (reverse)
                    {
                        cout << dq.back() << ",";
                        dq.pop_back();
                    }
                    else
                    {
                        cout << dq.front() << ",";
                        dq.pop_front();
                    }
                }
            }
            cout << "]" << endl;
        }
    }
}
