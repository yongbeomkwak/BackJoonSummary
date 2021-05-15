#include <iostream>

#define LMIT 501

int in[LMIT][LMIT];
int dp[LMIT][LMIT];

int max_(int a, int b) { return a > b ? a : b; } //값 비교하여 큰 값 리턴
using namespace std;
int main()
{
    int n = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            scanf("%d", &in[i][j]);
        }
    }

    dp[0][0] = in[0][0]; //삼각형의 가장 처음 값은 [0][0]에 초기화 시킴
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {

            if (j == 0) //j가 0이라는 뜻은 삼각형에서 왼쪽 변에 있다는 것이니 이 부분은 계속 왼쪽 변 값만 더하면됨
            {
                dp[i][j] = dp[i - 1][j] + in[i][j]; //바로 위쪽(i-1)에 위치했던 dp값 + 현재 위치 입력값(in)
            }
            else if (j == i) //마찬가지로 j와 i가 같다는 뜻은 가장 오른쪽에 위치한 값
            {
                dp[i][j] = dp[i - 1][j - 1] + in[i][j]; //왼쪽은 항상 인덱스가 0인데 그 전 행의 가장 오른쪽 값은 현재 j보다 1작은 j-1임
                //현재 dp는 바로 위쪽(i-1)의 오른쪽(j-1) + 현재 위치 입력값(in)
            }
            else // 나머지는 두가지 중에 고를 수 있음 (왼쪽,오른쪽) 왼쪽 =j-1 ,오른쪽은 j
            {
                dp[i][j] = max_(dp[i - 1][j - 1], dp[i - 1][j]) + in[i][j]; //바로 위의(i-1)의 왼쪽값(j-1) 또는 오른쪽(j) 값 + 현재 위치값
            }
            //dp는 누적합을 나타냄 
        }
    }
    /*
              7
            3   8      여기서 3과 8은 각각 가장 왼쪽과 오른쪽에 위치하므로 j==0 과 j==i일 때 조건문에 들어간다 
          8   1   0   8과 0은 가장 왼쪽과 오른쪽이고, 1은 3,8중에서 선택할 수 있음 ,즉 else문으로 들어감 ,여기서 3과 8을 고른다는 것은 그 전까지 합 중 큰값을 고를 수 있다는 뜻  
        2   7   4   4   여기서는  7과 4가 2개 중 하나를 고를 수있는 부분 
      4   5   2   6   5
    */
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        if (ans < dp[n - 1][i])
        {
            ans = dp[n - 1][i];
        }
        //n-1이 가장 마지막 행이기 때문에 그 모든 결과 중 최대값 찾기
    }
    printf("%d", ans);
}