#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main()
{
    int len = 0;
    int result = 0;
    string in;
    cin >> len >> in;
    string::iterator in_start = in.begin();
    for (int i = 0; i < len; i++)
    {
        int con_in = int(*(in_start + i)) - '0'; // 해당 string 의 각 char 접근 이후 - '0' 로  재대로 된 타입 캐스틍
        result += con_in;                        // sum
    }
    cout << result;
}