#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int roop = 0; //TestCase
    int cnt = 0;  // 그룹단어 갯수
    string str;

    scanf("%d", &roop);

    for (int i = 0; i < roop; i++)
    {
        bool check = true;     // 그룹단어인지 판단하기 위한변수
        bool roop_esc = false; //확실한 그룹변수가 아닐 때 바깥 반복문을 탈출하기 위한 변수
        cin >> str;
        if (str.length() == 1) //만약 문자열의 길이가 1이면 무조건 그룹단어
        {
            check = true;
        }
        else
        {
            for (int j = 0; j < str.length(); j++) //j 한글자를 기준으로
            {
                for (int k = j; k < str.length(); k++) //k가 문자열 끝까지 돔
                {
                    if (str[j] != str[k]) //만약 같지 않을경우 다음에 전에 나왔던 글자나오면 그룹문자 아닐 가능성이 커짐
                    {
                        for (int q = k; q < str.length(); q++) //현재 같지않은 위치를 시작으로 문자 끝까지 반복
                        {
                            if (str[j] == str[q]) //만약 현재 j가 한번 더 나오면 (즉aaabaa) j가 a(0)이 b를 만나면 이 roop로 들어오는데 a(4)를 만나면 그룹단어가 확실히 아님
                            {                     // 그 때
                                roop_esc = true;  //바깥 반복문 탈출 플래그를 true로
                                check = false;    //그룹단어를 명시
                                break;            //q for roop 탈출
                            }
                        }
                    }
                    else
                    {
                        check = true; // 같을 경우는 그룹단어
                    }
                    if (roop_esc)
                    {
                        break; // k for roop 탈출
                    }
                }
                if (roop_esc)
                {
                    break; //j for roop 탈출
                }
            }
        }
        if (check) //만약 그룹단어면 카운트 증가
        {
            cnt++;
        }
        else //그룹단어아니면 다시 입력받음
        {
            continue;
        }
    }
    printf("%d", cnt); //그룹단어 갯수 출력
}