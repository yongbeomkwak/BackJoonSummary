#include <bits/stdc++.h>

#define endl "\n"
using namespace std;

void hanoi(const int start, const int end, const int n)
{
    if (n == 1) //가장 큰 원판 옮기기
    {
        cout << start << " " << end << endl;
        return;
    }
    const int via = 6 - start - end;
    hanoi(start, via, n - 1);
    cout << start << " " << end << endl; // n번째 원판 이전(n-1)개까지 모두 옮김
    hanoi(via, end, n - 1);
}

int main()
{
    int n;
    cin >> n;
    string s = to_string(pow(2, n));
    int dot = s.find('.');
    s = s.substr(0, dot);
    s[s.length() - 1] -= 1;
    cout << s << endl;

    if (n <= 20)
        hanoi(1, 3, n);

    return 0;
}
