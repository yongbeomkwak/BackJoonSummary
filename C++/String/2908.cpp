#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
    string input1;     // 인풋1
    string input2;     // 인풋2
    string rev_input1; // 뒤집어서 저장할 변수1
    string rev_input2; // 뒤집어서 저장할 변수2
    cin >> input1 >> input2;
    string::reverse_iterator input1_rbegin = input1.rbegin(); //거꾸로 접근
    string::reverse_iterator input2_rbegin = input2.rbegin(); //거꾸로 접근

    for (auto k = input1_rbegin; k != input1.rend(); k++)
    {
        rev_input1.push_back(*k); //뒤에서 넣음
    }
    for (auto k = input2_rbegin; k != input2.rend(); k++)
    {
        rev_input2.push_back(*k); //뒤에서 넣음
    }
    /*

  stoi(string str,size_t* idx,int base) : string을 int로 바꿔줌
  1.str은 재료가될 string
  
  2.idx는 숫자와 문자가 섞여있을 때 사용 됨
  ex)
  rev_input1 와 rev_input2 가  숫자로  시작하여 문자와 섞여있을 때
  ex-> 1234ABC
  이렇게 되면 sz가 처음으로 문자가 나오는 인덱스인 4(A)를 가르키며 
  문자 전까지면 숫자로 바꿔줌
  size_t sz;
  int a=stoi(rev_input1,&sz);
  int b=stoi(rev_input2,&sz);

  만약 숫자만 있으면 nullptr 또는 그냥 생략하면됨

  3.base 는 진법을 나타냄 기본값은 10
   0 -> auto , 2-> 2진법, 8 -> 8진법, 16 -> 16진법
*/

    int a = stoi(rev_input1, nullptr); //변환
    int b = stoi(rev_input2, nullptr); //변환

    if (a > b)
    {
        printf("%d", a);
    }
    else
    {
        printf("%d", b);
    }
}