
#include <bits/stdc++.h>

using namespace std;

int main()
{

    string tmp = "";

    while (getline(cin, tmp))
    {

        if (tmp == ".")
            break;

        stack<char> st;
        for (const char &c : tmp)
        {
            if (c == '(' || c == '[')
                st.push(c);
            else if (!st.empty() && c == ')' && st.top() == '(')
                st.pop();
            else if (!st.empty() && c == ']' && st.top() == '[')
                st.pop();
            else if (c == ')' || c == ']')
            {
                st.push(c);
                break;
            }
        }

        if (st.empty())
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
}
