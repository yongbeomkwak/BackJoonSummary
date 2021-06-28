#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

void calchange(const int &change)
{
    int temp = change;
    int changearr[4] = {25, 10, 5, 1};
    int n_changearr[4] = {0, 0, 0, 0};
    for (int i = 0; i < 4; i++)
    {
        n_changearr[i] = temp / changearr[i];
        temp %= changearr[i];
    }
    cout << n_changearr[0] << " " << n_changearr[1] << " " << n_changearr[2] << " " << n_changearr[3] << "\n";
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int TC = 0;
    cin >> TC;
    for (int i = 0; i < TC; i++)
    {
        int change = 0;
        cin >> change;
        calchange(change);
    }
}
