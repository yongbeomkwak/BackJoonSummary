#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

#define LMIT 100001
using namespace std;

int item[102][2];
int dp[102][LMIT];
int max(int a, int b) { return a > b ? a : b; }
int main()
{
    int N = 0;
    int K = 0;

    scanf("%d %d", &N, &K);

    for (int i = 1; i <= N; i++)
    {
        scanf("%d %d", &item[i][0], &item[i][1]);
        // [i][0]=Weight, [i][1]=value
    }

    /*
     dp[i][j]=i번 째 물건까지 고려했을 때 j:실제 배낭의 무게 일 때 최대 value(가치)의 합 
    */
    for (int i = 1; i <= N; i++)
    {
        int W = item[i][0], val = item[i][1];
        // i번 째 물건의 무게, i번째 물건의 가치
        for (int j = 0; j <= K; j++)
        {
            //현재 배낭의 무게가 j이고,현재 고민중인 아이템의 무게 W보다 작을 때,
            //즉 그 물건은 가방에 담을 수 없으면
            if (j < W)
                dp[i][j] = dp[i - 1][j]; //그 전 아이템 까지 고려한 값을 넣어준다
            else
                dp[i][j] = max(dp[i - 1][j - W] + val, dp[i - 1][j]);
            //만약 담을 수 있으면 2가지 경우를 고려해야함 , 그 중 가치합이 높은 것을고른다
            //dp[i-1][j-W]+val: 그 전(i-1),가방무게-현재 물건 무게(j-W),+ val(이번 아이템의 가치)
            //dp[i-1][j]=그 전 아이템 까지 고려한 가치값
        }
    }
    printf("%d", dp[N][K]);
}