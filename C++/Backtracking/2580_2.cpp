#include <iostream>
#include <cstring>
#include <vector>
#include <sstream>   //istringstream 사용 (ㅎ)
#include <algorithm> // std::find
using namespace std;
int in[9][9] = {0};

void print() //결과 출력
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            printf("%d ", in[i][j]);
        }
        printf("\n");
    }
}
void insert(int row, int col)
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9}; //각 검사에서 나온 숫자들을 벡터에서 모두 제거한다

    if (in[row][col] != 0)
    {
        return;
    }
    else
    {
        for (int i = 0; i < 9; i++)
        {

            if (in[row][i]) //가로 검사(0이 아닐 때)
            {

                auto it = find(v.begin(), v.begin() + v.size(), in[row][i]); //find(시작,끝,찾을 값) ->찾을 시 해당 위치주소,없을 시 end 주소
                if (it != v.end())                                           //end가 아니면  찾았다는 것
                {
                    v.erase(it); //지움
                }
            }
        }
        for (int i = 0; i < 9; i++)
        {
            if (in[i][col]) //세로 검사(0이 아닐 때)
            {
                auto it = find(v.begin(), v.begin() + v.size(), in[i][col]); //find(시작,끝,찾을 값) ->찾을 시 해당 위치주소,없을 시 end 주소
                if (it != v.end())                                           //end가 아니면  찾았다는 것
                {
                    v.erase(it); //지움
                }
            }
        }
        int sub_row = 0;
        int sub_col = 0;
        sub_row = row / 3;
        sub_col = col / 3;
        sub_row *= 3;
        sub_col *= 3;
        // 정사각형 구역 검사를 하기위해서 해당 행,열 정보를 이용하여 sub 행,열을 만난다
        // / 연산자를 이용하여 나머지를 버리고 몫만을 얻은 후 (*3) 3을 곱하여 해당 행,열이 포함된 정사각형의 위치로 매핑된다

        //정사각형 구역 검사
        for (int i = sub_row; i < sub_row + 3; i++) //정사각형 가로
        {
            for (int j = sub_col; j < sub_col + 3; j++) //정사각형 세로
            {
                if (in[i][j]) //(0이 아닐 때)
                {
                    auto it3 = find(v.begin(), v.begin() + v.size(), in[i][j]);
                    if (it3 != v.end())
                    {
                        v.erase(it3); //마찬가지로 지움
                    }
                }
            }
        }

        if (v.size() == 1)
        {
            in[row][col] = v[0]; //모두 제거하고 남은 값(즉,1~9 중 하나도 나오지 않았던 값)
        }
    }
}

void bfs(const int &row, const int &col)
{
    int next_row = row;
    int next_col = col + 1;
    if (row == 9) // 행을 벗어나면 멈춤
    {
        return;
    }
    if (col == 9) // 열을 벗어나면 다음 열로 이동
    {
        next_col = 0;
        next_row += 1;
    }
    if (!in[row][col]) //값이 0일 경우 검사 필요 insert 실행
    {
        insert(row, col);
    }
    bfs(next_row, next_col); // 다음 스텝으로 이동
}
int main()
{

    for (int i = 0; i < 9; i++)
    {
        string a;
        getline(cin, a);     //한줄 입력받음(cin,string object)
        istringstream ss(a); // instringstream 변수(해당 string object) 공백과 줄바꿈 무시

        //만약 a가 1 2 3 4 5 6 7 8 9
        //ss는 123456789
        //ss>>  할 시 1 부터 하나씩 빼서 넣음
        for (int j = 0; j < 9; j++)
        {
            int val;
            ss >> val; //한 줄 입력받은 것에서 공백 기준으로 하나씩 들어감
            in[i][j] = val;
        }
    }

    bfs(0, 0);
    print();
}