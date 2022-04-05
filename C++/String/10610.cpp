#include <bits/stdc++.h>

using namespace std;

#define MAX 100001

int cnt[10];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string a;
    bool error = false; // error 플래그
    string ret;
    cin >> a;

    for (int i = 0; i <= 9; i++) // 0~9 개수를 카운ㅌ
    {
        cnt[i] = count(a.begin(), a.end(), (char)(i + 48)); // int to char
    }

    // 30의 배수 = 10배수 and 3의 배수 ,10 배수: 0이 존재해야 가능 ,3의 배수: 모든 수를 합할 시 3으로 나눠짐
    if (cnt[0] == 0)
        error = true; // 0이 없으면 10의 배수가 안됨
    else
    {
        int sum = 0;
        for (int i = 0; i <= 9; i++)
        {
            sum += i * cnt[i];
        }
        if (sum % 3 != 0)
            error = true; //모든 자리의 합이 3으로 나눠져야 3의 배수
        else
        {
            for (int i = 9; i >= 0; i--) // 내림차순이므로 9부터 해당 개수만큼 문자열에 붙힘
            {
                for (int j = 0; j < cnt[i]; j++)
                {
                    ret += (char)(i + 48);
                }
            }
        }
    }
    if (error)
        cout << -1; // error 존재 시 -1
    else
        cout << ret;
}
