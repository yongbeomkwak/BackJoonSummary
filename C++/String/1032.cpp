#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;

    string ans;
    string tmp;
    for (int i = 1; i <= N; i++)
    {
        if (i == 1)
            cin >> ans;
        else
        {
            cin >> tmp;
            for (int i = 0; i < ans.length(); i++)
            {
                if (ans[i] != tmp[i])
                {
                    ans[i] = '?';
                }
            }
        }
    }

    cout << ans << endl;
}
