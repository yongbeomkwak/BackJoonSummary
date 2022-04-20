#include <bits/stdc++.h>

using namespace std;

#define MAX 40001
#define INF 9876543

int n, b;
bool dp[31][15001];
int weight[31];
int bead;

void dpp(const int i, const int w) // i번째 추 ,현재무게 w
{
    if (i > n || dp[i][w] == true)
        return; //모든 추를 사용했거나 이미 방문했으면 true
    dp[i][w] = true;
    dpp(i + 1, w + weight[i]);      //현재 추 더하기,   추1 추2 = 구슬
    dpp(i + 1, abs(w - weight[i])); //현재추를 반대 쪽에 둠(구슬쪽)  구슬 추1 = 추2
    dpp(i + 1, w);                  // 이번 추 사용 안하고 넘어감
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> weight[i];

    dpp(0, 0); // 0번 째 추, 무게 0으로 시작

    cin >> b;

    for (int i = 0; i < b; i++)
    {
        cin >> bead;
        if (bead > 15000)
            cout << "N "; //추의 최대 무게 500 *30 초과시 측정불가
        else if (dp[n][bead])
            cout << "Y "; //측정된 값 있으면
        else
            cout << "N "; // 못 찾으면 N
    }
}
