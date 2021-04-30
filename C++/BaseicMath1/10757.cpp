#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <typeinfo>

using namespace std;

int main()
{
    string a;      //입력 받을 굉장히 큰 수 1
    string b;      //입력 받을 굉장히 큰 수 2
    string result; //최종 결과값

    cin >> a >> b; //입력 받음
    // 1 2 3 4 5  A
    // 5 4 3 2 1  B
    // 일 때 5 와 1 즉 일의 자리 부터 계산 해야하므로 뒤 부터 접근
    // 그러므로 iterator 와 begin이 아닌 reverse_iterator를 써야함 rbegin
    // 일의 자리 부터 접근
    string::reverse_iterator a_rev_iter = a.rbegin();
    string::reverse_iterator b_rev_iter = b.rbegin();
    int size_a = a.length();                      //A의 길이 얻음
    int size_b = b.length();                      //의 길이 얻음
    int roop = size_a > size_b ? size_a : size_b; //둘중 길이가 큰 값이 반복문의 끝값이 된다

    int ans = 0;                    // 각 자리 끼라 더했을 때 10이 넘어가면 저장할 변수
    int i_a = 0;                    //문자열 a 를 + 연산을 위해 int로 전환 시 사용 할 변수
    int i_b = 0;                    //문자열 b 를 + 연산을 위해 int로 전화 시 사용 할 변수
    for (int i = 0; i <= roop; i++) //반복문 에 <= 인 경우는 가장 큰 자리 수 값이 10 이 넘어 갈 때 그 값까지 계산하기 위해
    {
        //iter는 포인터 주소값을 가르킴 i를 통해 다음 문자를 저장한 주소 접근
        //만약 현재 가르키는 주소가 rend 보다 작아야 재대로 된 주소
        //만약 같거나 크면 가르키고 있는 값은 쓰레기 주소 값이 됨,굉장히 이상한 값이 나옴
        if ((a_rev_iter + i) < a.rend())
        {

            i_a = int(*(a_rev_iter + i)) - '0';
            //가르키는 문자값을 int로 casting 후 -'0' 을 빼줘 재대로 int로 바꿈
            // '0' 를 빼기 전 까지는 ASCII 형태임
        }
        else
        //  쓰레기 주소 값을 가르킬 때 그 때 값을 0으로 취급
        {
            i_a = 0;
        }

        // a의 조건과 같음
        if ((b_rev_iter + i) < b.rend())
        {
            i_b = int(*(b_rev_iter + i)) - '0'; // '0' =48
        }
        else
        {
            i_b = 0;
        }

        //ex  4 +8 -> 11 , num=2 ,ans=1
        int c_ans = i_a + i_b + ans; //현재 추출된 자릿수들의 값들과  ans를 더함
        int num = c_ans % 10;        // 더한 값중  일의 자릿수 저장

        ans = c_ans / 10; //10을 넘어 갔을 때 다음 덧셈을 위해 초기화

        //만약 9999 1 이면
        // i는 0부터 4까지 5번 반복
        // 이때 만약 i==roop 즉 마지막 반복시 num값이 0이면 추가하면안됨
        // 0이 아니란 소리는 1 즉 ans(전 자릿수에서 넘어온 값)가 1인 소리
        if (i == roop && num == 0) //만약 최종값이 0 이면 result 에 더하면 안됨 01234 이런식이 됨
        {

            break;
        }
        else //최종값이 0이 아니면 더해줘야함
        {

            result.insert(0, to_string(num)); //결과 값에 int를  string으로 캐스팅 후 일의 자리부터 하나씩 밀어 넣음
        }
    }
    cout << result << endl; //출력
}
