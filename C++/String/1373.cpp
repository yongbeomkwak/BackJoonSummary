#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string in;

    cin >> in;

    const int len = in.length();

    int i = 0;

    if (len % 3 == 1) //나머지가 1 -->   o xxx xxx xxx 구조
    {
        cout << in[0];
        i = 1; // i를 1로 옮김 0을 처리했으므로
    }
    else if (len % 3 == 2) // 나머지가 2 --> oo xxx xxx 구구조
    {
        cout << ((in[0] - '0') * 2) + (in[1] - '0');
        i = 2; // i를 2로 옮김 0과 1번째를 처리
    }

    for (; i < len; i += 3)
    {
        cout << ((in[i] - '0') * 4) + ((in[i + 1] - '0') * 2) + (in[i + 2] - '0');
    }
}
