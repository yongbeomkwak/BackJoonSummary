#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void solve(const int &L, const int &P, const int &V, const int &i)
{
    int K = L > V % P ? V % P : L;
    int result = ((V / P) * L) + K;
    cout << "Case " << i << ": " << result << "\n";
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int P, L, V = 0;
    int answer = 0;
    int i = 1;
    while (true)
    {
        cin >> L >> P >> V;
        if (P == 0 && L == 0 && V == 0)
        {
            break;
        }
        solve(L, P, V, i);
        i++;
    }
}
