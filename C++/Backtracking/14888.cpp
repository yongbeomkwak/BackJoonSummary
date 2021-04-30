#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 100000000
//pre processor 10억
int N = 0;
int operatorArr[4] = {0};     // +,-,*,/ 순으로 남은 개수
int num_Arr[100] = {0};       // 해당 연산을 할 수의 모음
int final_max = MAX * -1 - 1; //최댓값 초깃값 -10억 -1
int final_min = MAX + 1;      //최솟값 10억 +1
void back(int plus, int minus, int multiple, int divide, int n, int result)
{
    //매개변수로 각 연산자의 남은 개수를 받음, +,-,*,/ 순으로 , n은 현재 연산 횟수,result는 현재까지의 연산 결과
    if (n == N) //만약 연산 횟수가 N이 되면 모든 연산 끝
    {
        final_max = max(final_max, result);
        final_min = min(final_min, result);
        return;
    }
    // 1 2 3 4 5  일 때  처음 연산 해야할 놈은 2 즉 index로는 1이므로 n과 인덱스가 매칭된다
    if (plus > 0) //plus가 0보다 크면 아직 plus를 할 수 있음
    {
        back(plus - 1, minus, multiple, divide, n + 1, result + num_Arr[n]);
        // plus를해야하므로 현재 개수에서 -1 이후,연산 횟수 +1 ,결과값에 plus이므로 + 연산,현재 연산차례는 n임
    }
    //minus,multiple,divide 역시 같음
    if (minus > 0)
    {
        back(plus, minus - 1, multiple, divide, n + 1, result - num_Arr[n]);
    }
    if (multiple > 0)
    {
        back(plus, minus, multiple - 1, divide, n + 1, result * num_Arr[n]);
    }
    if (divide > 0)
    {
        back(plus, minus, multiple, divide - 1, n + 1, result / num_Arr[n]);
    }
}
int main()
{

    scanf("%d", &N); //연산 횟수 입력

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &num_Arr[i]); //연산에 사용할 숫자 입력
    }
    for (int i = 0; i < 4; i++)
    {
        scanf("%d", &operatorArr[i]); // 연산자 별 횟수 받음
    }
    back(operatorArr[0], operatorArr[1], operatorArr[2], operatorArr[3], 1, num_Arr[0]);
    //operatorArr 0(+),1(-),2(*),3(/), 시작부터 연산했다고 생각하고 1로 시작,초기값은 0인덱스(첫번째)

    printf("%d\n%d", final_max, final_min); //최대값 최솟값 출력
}