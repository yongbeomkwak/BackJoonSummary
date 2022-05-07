#include <bits/stdc++.h>

using namespace std;
#define MAX 10

int l, c;
vector<string> alpha;
bool ispos(const string s)
{
    int mcnt = 0;
    int jcnt = 0;
    for (const char c : s)
    {
        if (strchr("aeiou", c))
            mcnt++; //존재 유무(모음) 카운트
        else
            jcnt++; //모음 아니면 자음
    }

    if (mcnt >= 1 && jcnt >= 2)
        return true; //모음1개 이상 자음 2갱이상 일시 가능
    return false;
}

void task(int idx, string s)
{
    if (s.length() == l)
    {
        if (ispos(s))
            cout << s << endl;
        return;
    }
    for (int i = idx; i < alpha.size(); i++) //백트래킹
    {
        s += alpha[i];
        task(i + 1, s); //다음 것으로 이동
        s.pop_back();
    }
    return;
}
int main()
{
    cin >> l >> c;

    for (int i = 0; i < c; i++)
    {
        string tmp;
        cin >> tmp;
        alpha.push_back(tmp);
    }
    sort(alpha.begin(), alpha.end()); //정렬

    task(0, "");
}
