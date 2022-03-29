/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

typedef struct _INFO
{
    int v;
    string s;
} info;

char dx[] = {'D', 'S', 'L', 'R'};

int D(int a)
{
    return a * 2 % 10000;
}

int S(int a)
{

    if (a > 0)
        return a - 1;
    return 9999;
}

int L(int a)
{
    int left = a / 1000;
    int right = a % 1000;

    return right * 10 + left;
}

int R(int a)
{
    int right = a % 10;
    int left = a / 10;

    return right * 1000 + left;
}

int main()
{
    int tc = 0;
    cin >> tc;

    vector<string> ret;

    while (tc--)
    {

        int a, b;
        int *used;
        used = (int *)calloc(10000, sizeof(int));

        cin >> a >> b;
        queue<info> q;
        q.push({a, ""});
        used[a] = 1;
        while (!q.empty())
        {
            int now_v = q.front().v;
            string n_s = q.front().s;
            q.pop();

            if (now_v == b) // 같으면 그간 과정을 담는다.
            {
                ret.push_back(n_s);
                break;
            }

            for (int i = 0; i < 4; i++) // DSLR  차례대로 담아봄
            {
                int next_v;
                string next_s = n_s;
                if (dx[i] == 'D')
                {
                    next_s += 'D';
                    next_v = D(now_v);
                }
                else if (dx[i] == 'S')
                {
                    next_s += 'S';
                    next_v = S(now_v);
                }
                else if (dx[i] == 'L')
                {
                    next_s += 'L';
                    next_v = L(now_v);
                }
                else
                {
                    next_s += 'R';
                    next_v = R(now_v);
                }
                if (!used[next_v]) //방문하지 않았을 때만 큐에 담음
                {
                    used[next_v] = 1;
                    q.push({next_v, next_s});
                    continue;
                }
            }
        }
        free(used); //할당하제
    }

    for (const string &s : ret)
    {
        cout << s << endl;
    }
}
