#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string a, b;

    cin >> a >> b;

    const int len1 = a.length();
    const int len2 = b.length();

    int ret = 999;

    for (int i = 0; i <= len2 - len1; i++) //두 문자열 길이 차이 만큼 돈다, i는 b의 문자열 시작위치
    {
        int diff = 0;
        for (int j = i; j < i + len1; j++)
        {
            if (a[j - i] != b[j]) //두 문자열의 차이가 i이기 때문에 a는 j-1, b는 j 이다
                diff++;
        }
        ret = min(ret, diff);
    }
    cout << ret;
}
