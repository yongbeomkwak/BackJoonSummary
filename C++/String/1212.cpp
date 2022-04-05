#include <bits/stdc++.h>

using namespace std;

string arr1[8] = {"0", "1", "10", "11", "100", "101", "110", "111"}; //앞에 0이 없는
string arr2[8] = {"000", "001", "010", "011", "100", "101", "110", "111"};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string in;
    string ret;
    cin >> in;

    for (int i = 0; i < in.length(); i++)
    {
        if (i == 0)
            ret += arr1[in[i] - '0']; //가장 앞 문자일 때는 arr1을
        else
            ret += arr2[in[i] - '0']; //그 다음 부터는 arr2를
    }

    cout << ret;
}
