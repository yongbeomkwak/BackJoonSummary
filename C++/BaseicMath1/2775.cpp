#include <iostream>
#include <cstdio>

using namespace std;
int main()
{
    unsigned int tc = 0;       // Testcase 횟수
    int max_k = 0;             // 입력 받은 값 중에 가장 큰 K 값
    int max_n = 0;             // 입력 받은 값 중 가장 큰 n 값
    int k[3003] = {0};         // k값 만 저장할 배열
    int n[3003] = {0};         // n값 만 저장할 배열
    int arr[3003][3003] = {0}; //메모제이션을 위한 배열

    scanf("%d", &tc); // TestCase 입력 받음

    for (int i = 0; i < tc; i++)
    {
        scanf("%d %d", &k[i], &n[i]); // 각 k값 n 값을 입력 받음
        if (max_k <= k[i])
            max_k = k[i]; // 가장 큰 k값을 기억
        if (max_n <= n[i])
            max_n = n[i]; // 가장 큰 n 값을 기억
    }

    //i 가  층 , j가 호실
    for (int i = 0; i <= max_k; i++) //메모 제이션 시작(14x14 하면 낭비 될수 있으므로 최대 k와 n까지 진행)
    {
        for (int j = 1; j <= max_n; j++)
        {
            if (i == 0) //만약 0층 이면 현재인덱스의 +1 이 호실에 있는 사람의 수가 된다
            {
                arr[i][j] = j;
            }
            else //만약 0 층이 아니면
            {
                if (j == 1) //호실이
                {
                    arr[i][j] = 1;
                }
                else
                {
                    arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
                }
            }
        }
    }

    for (int i = 0; i < tc; i++)
    {
        printf("%d\n", arr[k[i]][n[i]]);
    }
}