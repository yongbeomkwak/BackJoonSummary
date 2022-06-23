#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define tab " "
#define MAX 1000000000
#define P pair<int, int>
int n;
string s;
bool check() //정확한 괄호 확인
{

    stack<char> st;
    for (const char &c : s)
    {
        if (st.empty())
        {
            st.push(c);
            continue;
        }

        char tmp = st.top();
        if (tmp == ')' || tmp == ']')
            return false;
        if (tmp == '(' && c == ')')
            st.pop();
        else if (tmp == '[' && c == ']')
            st.pop();
        else
            st.push(c);
    }

    return st.empty() ? true : false;
}

int task(string ss)
{
    int flag = true; //왼쪽 담을 플래그
    int obs = 0;     //
    string left;
    string right;
    for (int i = 0; i < ss.length(); i++)
    {
        if (flag) // flag가 true면 아직 왼쪽 담을 때
        {
            if (ss[i] == '(' || ss[i] == '[')
                obs++; //열리는 괄호면 +
            else
                obs--;     //아니면 --
            left += ss[i]; //왼쪽에 담음
            if (obs == 0)
                flag = !flag; //만약 0이되면 이제 왼쪽은 끝
            continue;
        }
        else //오른쪽 다음
        {
            right += ss[i];
        }
    }

    if (ss == left) //만약 입력과 left가 같다면, 더 이상 쪼갤 수 없거나 입력 그대로 담겨온 것 ex) (([[]])) 이런 경우
    {
        if (ss.size() == 2) //크기가 2라는 거은 더 이상 쪼갤 수 없음
        {
            if (ss[1] == ')')
                return 2; //) 일 때는  ()= 2  ] 때는 []=3
            else
                return 3;
        }
        left.clear();                           //왼쪽을 비워주고
        for (int i = 1; i < ss.size() - 1; i++) //양쪽 끝을 제외한 안에 것만 다음 (([[]])) -> (  ([[]]) =>이것만 다음 )
        {
            left += ss[i];
        }

        if (ss.back() == ')')
            return 2 * task(left); //가장 바깥이 )면 ()로 감싼 것이므로 *2
        else
            return 3 * task(left); //아니면 []로 감싼 것이므로 *3
    }

    return task(left) + task(right); //왼쪽 오른쪽 나눠서 진입
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;
    if (!check())
        cout << 0;
    else
        cout << task(s);

    return 0;
}
