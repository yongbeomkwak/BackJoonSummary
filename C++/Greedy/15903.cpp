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

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    priority_queue<long long int, vector<long long int>, greater<long long int> > pq;
    int m = 0;
    long long int m_0_ans = 0;
    long long int ans = 0;
    cin >> N >> m;

    for (int i = 0; i < N; i++)
    {
        long long int tmp = 0;
        cin >> tmp;
        m_0_ans += tmp;
        pq.push(tmp);
    }
    if (m == 0)
    {
        cout << m_0_ans;
    }
    else
    {
        for (int i = 0; i < m; i++)
        {
            long long int tmp1 = pq.top();
            pq.pop();
            long long int tmp2 = pq.top();
            pq.pop();
            long long int sum = tmp1 + tmp2;
            pq.push(sum);
            pq.push(sum);
        }
        for (int i = 0; i < N; i++)
        {
            ans += pq.top();
            pq.pop();
        }
        cout << ans;
    }
}
