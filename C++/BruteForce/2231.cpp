#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
    string a;
    cin >> a;
    int int_a = stoi(a);   //문자열을 int로
    bool find_sum = false; //찾았는지 확인할 플래그
    int k = 0;             //  최종 출력 값

    for (int i = int_a; i >= 1; i--) //입력받은 숫자부터 1까지 감소
    {
        int div_sum = 0;                                    //분해합
        string str_i = to_string(i);                        // 숫자를 문자열로
        div_sum += stoi(str_i);                             //  첫번 째 합은 자기 자신이므로 문자열을 숫자로 바꾼 후 더함
        for (auto j = str_i.begin(); j != str_i.end(); j++) //이후 문자 하나하나로 접근하기 위해서 string iterator사용
        {

            div_sum += int(*j) - '0'; //타입캐스팅 후 숫자 그대로 얻기위해 문자 0을 빼줌

            if (div_sum > int_a) //만약 크면 더 이상 볼 필요 없으므로 break
            {
                break;
            }
        }
        if (div_sum == int_a) //찾았으면  2중 for문안에 안 넣은 이유는 가장 작은 값을 찾기 위해 도중에 멈추지 않기 위해
        {
            k = i;           // 분해합 초기화
            find_sum = true; //찾음
        }
    }
    if (find_sum) //찾으면 k 출력
    {
        printf("%d", k);
    }
    else // 없으면 0 출력
    {
        printf("0");
    }
}