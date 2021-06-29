#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 500001
typedef pair<int, int> pai;
typedef vector<int>::iterator iter;
char input[MAX];
int N = 0;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int K = 0;
    string str;
    cin >> N >> K;
    cin >> str;
    deque<char> dq;
    for (size_t i = 0; i < str.length(); i++)
    {
        while (K && !dq.empty() && dq.back() < str[i]) // 아직 제거 할 갯수가 남아있고,dq가 비어있지 않고,
        //dq의 back(가장 최근에 추가한 수)가 str[i](현재 추가 될) 수보다 작다면 while 문을 순회 한다
        {
            dq.pop_back(); // back()(가장 최근에 추가한 수)를  꺼낸다.
            K--;           // (제거 하였으므로) K 감소
        }
        dq.push_back(str[i]);
    }
    for (size_t i = 0; i < dq.size() - K; i++)
    /*
        dq.size()-K 이유:
        보통 위 과정을 거치면 K=0인 데 
        4 2
        9988 일 때
        size()==4(9988) 이고 , 우리가 봐야할 것은 2개이므로(99)
        4-2= 2번 돌아야 한다 
     */
    {
        cout << dq[i];
    }
}
