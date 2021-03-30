#include <iostream>
#include <cstdio>
#include <string>
#include <array>
using namespace std;
int main()
{
    string in;
    cin >> in;                              //문자열 입력 받음
                                            //97
                                            //122
    array<int, 123> result;                 // 초기값을 0이아닌  값으로 하기위해 array library 사용
    result.fill(-1);                        // 초기값 -1 로 채움
    string::iterator in_start = in.begin(); // 시작 지점 가르킴
    for (int i = 0; i < in.size(); i++)     //해당 문자열 처음 부터 끝까지 roop
    {
        // *(in_start+i)) -> 현재 가르키고 있는 문자(char값) -> int(*(in_start+i)) ASCII code
        //  해당 ASCII code가 배열을 가르키는 index로 쓰임
        // 여기서 소문자 a~z 까지 이므로  97~122 까지가 된다
        if (-1 == result[int(*(in_start + i))]) // 그 값이 -1 라는 뜻은 해당 문자가 처음으로 나왔다는 뜻이므로
        {

            result[int(*(in_start + i))] = i; //그 문자 위치를 결과 배열에 저장한다 저장 시 저장 인덱스는 해당 ASCII code가 된다
        }
        else // -1 이 아닌경우 이미 값을 넣었다는 것이니깐 다음 반복분으로
        {
            continue;
        }
    }

    for (int i = 97; i <= 122; i++) // a~z 97 부터 122 까지 출력
    {

        int final_result = result[i];
        printf("%d ", final_result); //출력
    }
}