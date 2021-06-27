#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
typedef vector<int>::iterator iter;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, K = 0;
    cin >> N >> K;
    vector<int> input, plug;
    int ans = 0;
    for (size_t i = 0; i < K; i++)
    {
        int in;
        cin >> in;
        input.push_back(in);
    }
    for (iter it = input.begin(); it != input.end(); it++)
    {
        if (find(plug.begin(), plug.end(), *it) != plug.end()) // 해당 값을 찾아 다는 뜻(!=end) 그러면 넘어간다(이미 꽂혀있으니 뺄 필요 없 )
        {
            continue;
        }
        if (plug.size() < N) //아직 플러그가 꽉 차지 않음
        {
            plug.push_back(*it); //꼽는다
            continue;
        }
        //여기까지 왔으면 이미 plug는 꽉 찮거
        iter last = it, idx = plug.begin();
        for (iter t = plug.begin(); t != plug.end(); ++t)
        {
            iter temp = find(it + 1, input.end(), *t); // it+1 인 이유:lt 까지는 위에서 삽입 plug쪽에 삽입이 됨,아마 it는 마지막 으로 꽂힌 듯 ,
            //*t 값을 찾는 다는 것은 이미 꽂힌 것 중 나중에 꽂야야 할 것이 존재하는 지 확인

            if (temp > last)  //end 즉 위에서 찾지 못해도 들어오긴 하지만 전혀 상관없음  어차피 위에서 다시 last를 초기화 해줌 
            {   
                //만약에 찾았고, 그 값이 가장 마지막에 삽입된 놈보다 뒤에 있다면 , 나중에 꽂야 할 것이 존재한다는 뜻, 즉 지금도 꽂혀있고 나중에도 꽂아야 하므로 빼면안됨
                idx = t;     //밑에서 플러그 뽑기 위해  
                last = temp; //다음 검사 시 현재보다 뒤에를 검사 할 수 있도록 이동(즉 가장 나중에 다시 껴야하거나,앞으로 낄 계획이 없는 얘를 찾기위해)
            }
        }
        *idx = *it;// 플래그 뽑기 , *it(이제 꼽아야하는 플러그),idx= 플래그 위치
        ans++;
    }
    cout << ans;
}
