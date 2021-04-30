#include <iostream>
#include <cstdio>
using namespace std;
bool check[14][14] = {
    false,
};
int ans = 0;
int N;

bool valid(const int &row, const int &col)
{
    // 가로 ,세로 , 대각선 2개 검사 해야함
    int x, y;
    for (x = 0; x < col; x++)
    {
        if (check[row][x]) // 현재 위치 전까지 x방향(열) 이동  했을 때 하나라도 true 있으면 queen 못 놓음 false return
            return false;
    }
    for (y = 0; y < row; y++)
    {
        if (check[y][col]) //현재 위치 전까지 y방향(행) 이동 했을 때 하나라도 true면 false
            return false;
    }
    for (x = col - 1, y = row - 1; y >= 0; x--, y--) //현재 위치를 기준으로 좌(x--) 상(y--) 대각선 조사
    {
        if (check[y][x])
            return false;
    }
    for (x = col - 1, y = row + 1; y < N; x--, y++) //현재 위치를 기준으로 좌(x--) 하(y++) 대각선 조사
    {
        if (check[y][x])
            return false;
    }
    //대각선은 > 모양으로 (조회) < (우 상,우 하)를 조사 하지 않는 이유는
    //현재 위치의 과거 값은  왼쪽 값이다,dfs가 행 이동을 하기 때문에 열(가로) 과거 값만 봄
    // 위 4가지 조건을 모두 통과 시 true(queen)놓을 수 있음
    printf("%d %d \n", row, col);
    return true;
}

void dfs(int curr_col) //현재 열
{
    if (curr_col == N) //현재 열이 마지막 열까지 왔을 때
    {
        ans++; //갯 수 증가
        return;
    }
    else
    {
        for (int row = 0; row < N; row++) // 행 (y)이동
        {
            if (!check[row][curr_col] && valid(row, curr_col)) //열을 기준으로 행을 반복하여 체크함
                                                               //가리키고 있는 값이 false 이고 vaild 함수를 통과하면 놓을 수 있음
            {
                check[row][curr_col] = true;

                dfs(curr_col + 1); //다음 열 조사
                check[row][curr_col] = false;
            }
        }
    }
}
int main()
{
    scanf("%d", &N);
    dfs(0); // 0 열 부터 조사
    printf("%d", ans);
}