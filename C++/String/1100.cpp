#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;

    string odd = "F.F.F.F.";
    string even = ".F.F.F.F";
    int ans = 0;
    for (int i = 1; i <= 8; i++)
    {
        string tmp;
        cin >> tmp;
        if (i % 2 != 0)
        {
            for (int i = 0; i < 8; i++)
            {
                if (tmp[i] == 'F' && odd[i] == 'F')
                    ans++;
            }
        }
        else
        {
            for (int i = 0; i < 8; i++)
            {
                if (tmp[i] == 'F' && even[i] == 'F')
                    ans++;
            }
        }
    }

    cout << ans;
}
