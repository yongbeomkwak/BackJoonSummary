#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
bool checkEndNumber(const string &str)
{
    //.find: 해당 문자열 안에 매개변수가 있으면 찾은 시작 인덱스를 반환
    // 못 찾을 시 string::npos 리턴
    if (str.find("666") == string::npos) // 못 찾았다는 뜻
    {
        return false; //그 때 false
    }
    return true; //찾으면 true
}
int main()
{
    string N;
    cin >> N;
    int int_N = stoi(N); //string -> int
    int count = 0;
    int start = 665;       //시작은 666전인 665
    while (count != int_N) //count 값과 입력 받은 값이 같으면 종료
    {
        start++;                              //start  증가
        if (checkEndNumber(to_string(start))) //해당 start변수를 string으로 convert 후 check함수로 넘겨줌
        {
            count++; //true 면 count 증가
        }
    }
    printf("%d", start); //출력
}