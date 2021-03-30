#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    string str;
    getline(cin, str);                       //한줄 입력 받기 (cin,string)
    char *cstr = new char[str.length() + 1]; // string -> char 로 바꾼 값 담을 배열
    strcpy(cstr, str.c_str());               // string을 char로(c_str()) 바꾼후 cstr에 담기 (strcpy())
    char *ptr = strtok(cstr, " ");           // " "로 구분 하여 구분된 첫번째 문자 주소 기억(strtok(해당 char 배열,구분자))
    int count = 0;
    while (ptr != NULL)
    {
        count++;
        ptr = strtok(NULL, " "); // 만약 해당 문자열 자리(첫번 째 인자)가 NULL 일경우 다음 단어로 넘어감
    }
    printf("%d", count);
}