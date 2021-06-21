#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N = 0;
    int answer = 0;
    cin >> N;
    priority_queue<int, vector<int>, greater<int> > pq; //type:int ,Container vector,오름차순
    for (size_t i = 0; i < N; i++)
    {
        int temp = 0;
        cin >> temp;
        pq.push(temp);
    }
    while (pq.size() != 1)
    {
        int temp1 = pq.top();
        pq.pop();
        int temp2 = pq.top();
        pq.pop();
        answer += (temp1 + temp2);
        pq.push(temp1 + temp2);
    }
    cout << answer << "\n";
}
