#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
typedef pair<int, int> pai;

int N = 0;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    string input;
    cin >> input;
    int ans = 0;
    char prev;
    int lcount = 0;
    int roop = 0;
    if (N <= 2)
    {
        ans = N;
        cout << ans << "\n";
    }
    else
    {
        ans = 1;
        while (roop < input.size())
        {

            if (ans < N)
            {
                if (input[roop] == 'S')
                {
                    roop++;
                    ans++;
                }
                else
                {
                    roop += 2;
                    ans++;
                }
            }
            else
            {
                break;
            }
        }
        cout << ans;
    }
}
