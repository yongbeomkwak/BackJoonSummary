#include <bits/stdc++.h>

using namespace std;

#define FAULT "FRULA"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    getline(cin, s);
    bool istags = false; //태그가 열렸나?
    stack<char> st;
    for (const char &c : s)
    {
        if (c == ' ') // 공백일 때 스택에 요소가 있을 경우 출력함
        {
            while (!st.empty())
            {
                cout << st.top();
                st.pop();
            }
            cout << c; //공백
            continue;
        }
        if (c == '<') //태그를 열기전에 스택에 요소가 있을 경우 출력
        {
            while (!st.empty())
            {
                cout << st.top();
                st.pop();
            }
            istags = true; //태그 열음
            cout << c;     //태그 열음
            continue;
        }
        else if (c == '>') //태그 닫음
        {
            cout << c;
            istags = false; //닫음
            continue;
        }
        if (istags)
            cout << c; //태그가 열렸을 경우 그대로 출력
        else           //아닐경우 스택에 담음
        {
            st.push(c);
        }
    }
    while (!st.empty()) //마지막 스택 체크
    {
        cout << st.top();
        st.pop();
    }
}
