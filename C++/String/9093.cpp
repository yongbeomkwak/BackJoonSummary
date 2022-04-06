#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--)
    {
        string in;
        string ret;

        getline(cin, in);              //공백 포함 받은 후
        reverse(in.begin(), in.end()); //모든 문자열을 뒤집고 (i love u) -> (u evol i)
        string tmp;
        stringstream ss(in); //스트링 스트림에 넣어놓고

        while (getline(ss, tmp, ' ')) //빈칸 기준으로 나누고
        {
            string tt = ret;      //이전 값
            ret = tmp + " " + tt; //새로운 값 + 빈칸 + 이전 값을 쌓음
        }

        cout << ret << endl;
    }
}
