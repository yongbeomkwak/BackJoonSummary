#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool compare(string &a, string &b)
{
    return a.size() > b.size() ? true : false;
}

bool comp(int &a, int &b)
{
    return a > b ? true : false;
}

vector<string> v;
vector<int> num(26);
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N = 0;
    string a;
    scanf("%d", &N);
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        string prev;
        cin >> prev;
        v.push_back(prev); //string 입력 받음
    }
    sort(v.begin(), v.end(), compare); //일단 길이를 기준으로 정렬
    for (string &s : v)
    {
        int size = pow(10, s.size() - 1); //해당문자열 길이가 3 이면, 100의 자리수 그러므로,10의 3-1 승== 10^2
        for (char &c : s)                 //해당 string 에서  char로 하나씩 받아
        {
            num[int(c) - 65] += size; // A=65이므로 A=0으로 매칭 시키기 위 -65
            size /= 10;               // 다음 자릿수 이므로 10으로 나눔
        }
    }
    sort(num.begin(), num.end(), comp); //이후  다항싱 형태를 하기 위해 , 누적된 합이 큰 순으로 정렬 (내림차순 )
    int re_num = 9;
    for (int i = 0; i < 26; i++)
    {
        if (num[i] == 0)
            break;              //0 이면 한번도 호출 안되었다 즉시 종료
        sum += num[i] * re_num; //다항식 100 *A(9) .. 이런 식으로 ,결과에 더함
        re_num--;               //9->8->7... 점점 감소
    }
    cout << sum << endl; //결과 출력
}
