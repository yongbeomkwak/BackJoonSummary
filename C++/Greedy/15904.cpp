#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 500001
typedef pair<int, int> pai;
typedef vector<int>::iterator iter;
char input[MAX];
int N = 0;

bool comp(const int &a, const int &b)
{
    return a > b;
}
int min(const int &a, const int &b)
{
    return a < b ? a : b;
}

void checkUCPC(const string &str)
{
    char ucpc[4] = {'U', 'C', 'P', 'C'};
    size_t n = 0;
    for (int i = 0; i < 4; i++)
    {
        size_t temp = str.find(ucpc[i], n);
        if (temp == string::npos)
        {
            cout << "I hate UCPC";
            return;
        }
        else
        {
            n = temp + 1;
        }
    }
    cout << "I love UCPC";
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string str;
    getline(cin, str);
    checkUCPC(str);
}
