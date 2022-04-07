#include <bits/stdc++.h>

using namespace std;

#define MOVE 13

// abcde fghij klm nop

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string in;
    getline(cin, in);

    for (char &c : in)
    {
        if (islower(c))
        {
            if (c - 'm' > 0) // m 보다 크면 13만큼 빼주고
            {
                c = (char)(c - MOVE);
            }
            else // m 보다 작으면 13만큼 더해준다
            {
                c = (char)(c + MOVE);
            }
        }
        if (isupper(c))
        {
            if (c - 'M' > 0) // M보다 크면 13만큼 빼주고
            {
                c = (char)(c - MOVE);
            }
            else // M보다 크면 13만큼 더해준다.
            {
                c = (char)(c + MOVE);
            }
        }
    }
    cout << in;
}
