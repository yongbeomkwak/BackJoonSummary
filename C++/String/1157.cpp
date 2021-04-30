#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm> // std::transform 을 위한
#include <functional>
#include <map>
using namespace std;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string input;
    cin >> input;
    map<char, int> temp_map;          // Map  생성
    for (char k = 'A'; k <= 'Z'; k++) // MAP 에  [A,0] .. [B,0] .. 값 삽입
    {
        temp_map.insert(pair<char, int>(k, 0)); //삽입 시 반드시 pair 클래스이용, pair 클래스는 두 타입을 묶어 하나로 만들어줌
    }

    /*for(auto k=temp_map.begin();k!=temp_map.end();k++)
    {
     //key 접근 시  first, value 접근 시 second로 접근 한다 
      
      cout << "key:"  << " " <<k->first  << " " <<"value:" << " " << k->second <<endl;  
      
      
    }*/

    //transform은 2가지 형태가 있음
    // op에 사용되는 함수의 인자가 1개이냐 2개이냐에 따라 달라짐
    //transform(first1,last1,d_first,op)
    //transform(first1,last1,d_first,first2,op)

    /* op가 인자 1개만 필요할 경우
  1.transform(first1,last1,d_first,op)
    
(first1,last1]  -> first1 이상 last1 미만 까지 각 값에 접근하여
  op에 있는 함수에 대하여 계산 후
  d_first에 차례대로 저장한다, 거의 begin() 임*/

    /*op 인자가 2개일 경우 
    2.transform(first1,last1,first2,d_first,op)
    
    마찬가지로 first1이상 last1미만 까지 추출한 각 원소와 
    first2로 시작하여 last1-first1까지 각 원소 추출하여 op 함수 계산 이후
    d_first에서 부터 저장,거의 begin() 임
    중요한 것은 first2는 last2가 없기 때문에 first1과 last1 차이만큼 first2가 움직임
    
ex)
      std::vector<int> foo={1,2,3,4,5,7};
      std::vector<int> bar={5,4,3,2,1};
      std::vector<int> ccc={0,0,0,0,0,0}; 
      
      transform(foo.begin(),foo.end(),bar.begin(),ccc.begin(),plus<int>());
      foo 1 ~7까지 총 6개
      bar 5 ~1까지 총 5개
      first1 last1 -> 1~7  까지 차례로 접근,
      first2 부터  foo의 갯수만큼 6번 접근 5 4 3 2 1 0(값이 없음)
      ccc.begin() 에 넣음  ccc는 6 6 6 6 6 7  이됨 
     
*/

    transform(input.begin(), input.end(), input.begin(), ::toupper); // 대문자로 덮어 씀
    for (auto k = input.begin(); k != input.end(); k++)              //문자열 하나씩 접근
    {
        auto find_char = temp_map.find(*k); //해당 문자를 key로 .find(key) 를 함, .find는 해당 key 값을 갖고 있으면 그 key의 주소를 반환 함
        if (find_char != temp_map.end())    //만약 그 주소가 end가 아니면 찾았다는 거고, end면 못찾은거임
        {
            temp_map.at(*k) += 1; // .at(key) 해당 key갑에 대한 value 값을 1 증가
        }
        else //찾지 못할경우  다음 반복
        {
            continue;
        }
    }

    int max = 0;   //최대값을 저장할 변수
    char max_char; //최대값에 대한 문자
    for (auto k = temp_map.begin(); k != temp_map.end(); k++)
    {
        //key 접근 시  first, value 접근 시 second로 접근 한다
        if (max <= k->second) //만약 해당 second 즉 value 값이 max 보다 같거나 크면
        {
            max = k->second;     //다음 max 값으로 초기화
            max_char = k->first; //최대값 문자도 초기호ㅓㅏ
        }
    }
    // 여기까지 최대값과 최대값에 대한 문자를 찾음
    int check_dup = 0; //미지막으로 최대반복 문자가 1개를 초과하는지 조사
    for (auto k = temp_map.begin(); k != temp_map.end(); k++)
    {
        if (check_dup > 1) // 만약 1개 이상이면 (1개 일경우 위에서 찾은 그 문자일 수도있으므로 2부터 중복)
        {
            cout << "?"; // ? 출력
            return 0;    //하며 종료
        }
        else //아닐 경우
        {
            if (k->second == max) //찾은 max값과 해당 key에 대한 value 값이 같을 경우
            {
                check_dup++; // 중복 체크 값을 하나 증가 시킨다
            }
        }
    }
    cout << max_char;
}