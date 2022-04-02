#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    unordered_map<string, int> um;
    priority_queue<string, vector<string>, greater<string> > pq;
    for (int i = 0; i < N + M; i++)
    {
        string tmp;
        cin >> tmp;
        if (i < N)
        {
            um[tmp] = 1;
        }
        else
        {
            if (um[tmp] == 1)
                pq.push(tmp);
        }
    }

    cout << pq.size() << endl;

    while (!pq.empty())
    {
        cout << pq.top() << endl;
        pq.pop();
    }
}
