#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
    string str;
    cin >> str;
    string::iterator str_begin = str.begin();
    int total = 0;
    while (str_begin != str.end())
    {

        if (*(str_begin + 1) == '=') //다음 문자가  '=' 일 때, 그 전 문자가 c,s,z 면 단어 하나로 취급하고,가르키는 문자를 2칸 이동
        {
            if (*(str_begin) == 'c' || *(str_begin) == 's' || *(str_begin) == 'z')
            {
                total++;
                str_begin += 2;
            }
        }
        else if (*(str_begin + 1) == '-') //다음 문자가 '-'일 때, 그 전 문자가 d,c 면 마찬가지로 단어 하나로 취급하고,가르키는 상태를 2칸 이동
        {
            if ((*(str_begin) == 'd') || (*(str_begin) == 'c'))
            {
                total++;
                str_begin += 2;
            }
        }
        // dz= 단어하나 취급 후 3칸 이동
        else if (*(str_begin) == 'd' && *(str_begin + 1) == 'z' && *(str_begin + 2) == '=')
        {
            total++;
            str_begin += 3;
        }
        // 다음 문자가 j고 현재 문자가 l 또는 n 일 때 단어 하나로 취급 가르키는 상태 2칸 이동
        else if (*(str_begin + 1) == 'j' && (*(str_begin) == 'l' || *(str_begin) == 'n'))
        {
            total++;
            str_begin += 2;
        }
        else
        {
            total++;
            str_begin++;
        }
    }
    printf("%d", total);
}