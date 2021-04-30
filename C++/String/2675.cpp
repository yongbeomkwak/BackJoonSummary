#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main()
{
    int tc;        // TestCase
    int roop;      // 반복 횟수
    string in;     // 인풋 문자열 값
    string result; //결과로 사용될 문자열 값

    scanf("%d", &tc);            // testcase 입력 받기
    for (int i = 0; i < tc; i++) // testcase 만큼 반복
    {
        cin >> roop >> in;                      //  반복 횟수와 문자열 입력 받음
        string::iterator in_start = in.begin(); // 반복자 얻기
        for (int j = 0; j < in.length(); j++)   //해당 문자열 길이 만큼 반복
        {
            for (int k = 0; k < roop; k++) // 입력 받은 반복 홧수 만큼
            {

                result.push_back(*(in_start + j)); // 결과 변수인 result 뒤로 차례대로 반복하여 넣음
            }
        }

        cout << result << endl; //결과값 출력
        result.clear();         //다음 반복을 위해 결과 변수 비움
    }
}