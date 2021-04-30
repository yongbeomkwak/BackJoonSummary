#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int sudoku_arr[9][9] = {0};

// 수도쿠 값을 출력해준다.
void print_sudoku()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << sudoku_arr[i][j];
            if (j != 8)
                cout << " ";
        }
        cout << endl;
    }
}

void sudoku_slove(int row, int col)
{
    // 위치에서 가능한 값을 체크한다. (가능한 값을 배열에 넣자)
    int used_num_arr[9] = {0};
    vector<int> each_round_can_vec;

    // 가로 세로 체크
    for (int i = 0; i < 9; i++)
    {
        if (sudoku_arr[row][i])                       //가로 체크
            used_num_arr[sudoku_arr[row][i] - 1] = 1; //인덱스는 0 , 스도쿠 값은 1부터 시작하므로  -1을 해줘 인덱스로 사용 후,사용한 인덱스 값은 1로 바꿔줌
        if (sudoku_arr[i][col])                       //세로 체크
            used_num_arr[sudoku_arr[i][col] - 1] = 1;
    }

    // 그룹의 첫번째 시작놈을 기준으로 인덱스 설정
    int sub_row = row / 3, sub_col = col / 3;
    sub_row *= 3;
    sub_col *= 3;

    // 정사각형 그룹체크
    for (int i = sub_row; i < sub_row + 3; i++)
    {
        for (int j = sub_col; j < sub_col + 3; j++)
        {
            if (sudoku_arr[i][j])
                used_num_arr[sudoku_arr[i][j] - 1] = 1;
        }
    }

    // 사용되지 않은 숫자들을 전부 벡터에 넣어준다.
    for (int i = 0; i < 9; i++)
    {
        if (!used_num_arr[i])                    //해당 값이 0 이면 , 즉 한번도 사용되지 않을 경우
            each_round_can_vec.push_back(i + 1); //백터에 넣음  i=0 이란 뜻은 1을 한번도 안썼다는 뜻이니 i+1
    }

    // 사용되지 않은 숫자가 없으면 그냥 리턴하고, 있으면 해당 위치에 값을 넣고 재귀함수로 다음 단계로 간다.
    if (!each_round_can_vec.size())
        return;

    //  다음 단계로 넘어간다.
    int next_row = row, next_col = col;
    while (true)
    {
        // 다음 컬럼이 9가 되면
        if ((++next_col) == 9)
        {
            next_row++;
            next_col = 0;
            // 만약 모든 수가 끝났다면, 프린트하고 종료한다.
            if (next_row == 9)
            {
                sudoku_arr[row][col] = each_round_can_vec[0]; //마지막은 벡터에 하나만 있으므로 검사가 끝난 벡터에서 첫번째 값을 바로 넣음
                print_sudoku();
                exit(0);
            }
        }
        if (next_row == 9)
            break;
        if (sudoku_arr[next_row][next_col] == 0) //다음 값이 0이면 다시 검사를  해야 하므로 while 벗어남
            break;
    }

    for (int i = 0; i < each_round_can_vec.size(); i++)
    {
        //만약 가능성이 있는 값이 1 , 5 ,7,8 이면 하나씩 넣은 후 다음 스텝으로 진행함,
        // 만약 리턴하여 빠져나올 경우, 다음 경우인 5로 다시 탐색 들어감
        sudoku_arr[row][col] = each_round_can_vec[i]; // 검사에서 남은 값들을 차례대로 넣고
        sudoku_slove(next_row, next_col);             //다음 단계로 넘어감
        sudoku_arr[row][col] = 0;                     //이후 다시 값을 돌려놓아서 다음 값으로 확인해봄
    }
}

int main()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> sudoku_arr[i][j];
        }
    }

    // 그룹 체크
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (sudoku_arr[i][j] == 0)
            {
                sudoku_slove(i, j);
            }
        }
    }
    return 0;
}