#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;

    cin >> tc;

    while (tc--)
    {
        deque<int> dq; //덱 선언 
        bool error = false, reverse = false; //error 플래그와 reverse 플래그
        string command, arr;
        int n;
        cin >> command;
        cin >> n;
        cin >> arr;

        string tmp = "";
        for (const char &c : arr)
        {
            if (isdigit(c)) //만약 숫자면 
                tmp += c; //누적 
            else //다른 것이 들어오면 지금까지 누적한 숫자문자열을 int로 변환
            {
                if (tmp.empty())  //비어있으면 continue
                    continue;
                dq.push_back(stoi(tmp)); 
                tmp.clear(); //비워주고 
            }
        }

        for (const char &c : command)
        {
            if (c == 'R') //만약 R이면 reverse
                reverse = !reverse;
            else //만약 D인데 
            {
                if (dq.size() == 0) //아무것도 없으면 error 플래그 켜주고 중단 
                {
                    error = true;
                    break;
                }

                if (reverse) //만약 뒤집힌 상태에서 D면 뒤에 것 제거
                    dq.pop_back();
                else
                    dq.pop_front(); //앞에꺼 제거
            }
        }

        if (error) //error면 error
            cout << "error" << endl;
        else
        {
            cout << "[";
            while (!dq.empty())
            {
                if (dq.size() == 1) //덱에 하나 뿐이면 뒤에 ,(쉼표)는 없어야함
                {
                    cout << dq.front();
                    dq.pop_front(); 
                }

                else
                {
                    if (reverse) //뒤집힌 상태면 back면 back에서 부터 배출 
                    {
                        cout << dq.back() << ",";
                        dq.pop_back();
                    }
                    else //아니면 앞 부터 배출
                    {
                        cout << dq.front() << ",";
                        dq.pop_front();
                    }
                }
            }
            cout << "]" << endl;
        }
    }
}
