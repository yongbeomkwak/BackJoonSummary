#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>

#define LMIT 51

using namespace std;
int main()
{
    int result = 0;
    bool plus = true;
    string str, tmp;
    cin >> str;
    for (int i = 0; i <= str.size(); i++)
    {

        if (str[i] == '+' || str[i] == '-' || str[i] == '\0')
        {
            if (plus) //plus면 더함
            {
                result += stoi(tmp);
            }
            else //뺌
            {
                result -= stoi(tmp);
            }
            if (str[i] == '-') //한번 마이너스 만나면 그다음부터는 계속 뺌,뒤엣 +여도 괄호로 묶어서 -(a+b) 형태로 결국 -로 만듬
            {
                plus = false;
            }
            tmp = ""; //초기화
            continue;
        }
        tmp += str[i];
    }
    printf("%d", result);
}