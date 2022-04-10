#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    string s;
    
    cin >> s;
    int ret=0;
    for(int i=0;i<s.length();i++)
    {
        if(strchr("aeiou",s[i]))ret ++;
        /*
         char* strchr (char* str, int c);
         해당 문자열(str)에 해당 문자 c가 존재하면 해당 존재하는 곳 포인터 없으면 Null
         */
    }
    cout <<ret;
}
