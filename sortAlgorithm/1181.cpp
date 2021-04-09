#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

bool comp(const string &a, const string &b)
{
    if (a.length() < b.length())
    {
        return true;
    }
    else if (a.length() == b.length())
    {
        return a < b; //사전 오름 차순
    }
    return false;
}

int main()
{
    int tc = 0;
    vector<string> v; //pair 객체로 저장
    string s;
    scanf("%d", &tc);
    for (int i = 0; i < tc; i++)
    {
        cin >> s;
        v.push_back(s);
    }
    sort(v.begin(), v.end(), comp);
    v.erase(unique(v.begin(), v.end()), v.end()); //vector 안 중복값 제거,반드시 정렬 한 뒤 사용해야함
                                                  //v.erase(a,b) -> [a,b) a이상 b 미만 원소 제거(a와 b는 vector iteraotr)
                                                  /*
unique(a,b) a와 b는 vector iterator 
vector 배열에서 중복되지 않는 원소들을 앞에서부터 채워나가는 함수이다.
algorithm 헤더에 존재한다.
중복되지 않는 원소들을 앞에서부터 채워나가는 역할을 하기때문에 남은 뒷부분은 그대로 vector 원소값이 존재한다.   
*/
    for (auto k = v.begin(); k != v.end(); k++)
    {
        cout << *k << endl;
    }
}