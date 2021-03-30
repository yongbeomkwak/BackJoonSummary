#include <iostream>
#include <cstdio>
#include <array>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define MAX 10001

void gold(const vector<int> vec, int &num)
{
    int A = 0;
    int B = 0;
    int min = 9999; //최솟값을 높게 설정
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] >= num) //만약 백터의 값이 입력같보다 높을 경우 두수의 합으로 나타낼 수 없으므로 멈춤
        {
            break;
        }
        else
        {
            for (int j = 0; j < vec.size(); j++)
            {
                if (vec[j] >= num) //마찬가지로 두 수 중 하나가 입력값보다 높으면 합으로 나타낼수 없음
                {
                    break;
                }
                else
                {
                    if ((vec[j] + vec[i]) == num) //두수의 합이 입력값과 같을 때
                    {
                        int temp = vec[i] - vec[j]; //어떤값이 클지 i가 크면 양수  i가 작으면 음수
                        int abs_temp = abs(temp);   //실질적인 차이 절대값 사용
                        if (min > abs_temp)         //절대값이 최소값보다 작을 경우
                        {
                            min = abs_temp; //다음 최소값으로 사용
                            if (temp > 0)   // temp가 양수면 i가 크고 temp가 음수면 i가 작음 무조건 작은값을 A에 담음
                            {
                                B = vec[i]; //큰값
                                A = vec[j]; //작은값
                            }
                            else
                            {
                                A = vec[i]; //작은값
                                B = vec[j]; //큰 값
                            }
                        }
                    }
                }
            }
        }
    }
    printf("%d %d\n", A, B); //출력
}

int main()
{
    int M = 0;
    int N = 0;
    array<bool, MAX> primeArray; // 1~1000000  사용
    primeArray.fill(true);       //초기값 true로
    primeArray[0] = false;       // 0 과 1은 무조건 소수가 아니므로
    primeArray[1] = false;
    //에라토스테네스의 체
    for (int i = 2; i <= MAX; i++) // 반복문을 sqrt(i) 번 반복하기위해 i*i
    {
        if (primeArray[i]) //만약 true 일 경우
        {
            for (int j = 2 * i; j <= MAX; j += i) // 즉 i=2 이면(2는 소수) 4부터 시작하기 위해 j=i*i그 배수 관계(j+=i)는 모두 false로 만듬`
            {
                if (primeArray[j] == false)
                {
                    continue;
                }
                primeArray[j] = false;
            }
        }
    }
    vector<int> vec;
    for (int i = 2; i < MAX; i++) //해당 범위 안에서 소수들만 따로 백터에 넣음
    {
        if (primeArray[i])
        {
            vec.push_back(i);
        }
    }
    int tc = 0;
    scanf("%d", &tc);
    for (int i = 0; i < tc; i++)
    {
        int num = 0;
        scanf("%d", &num);
        gold(vec, num); //백터와 해당 값 넘겨줌
    }
}