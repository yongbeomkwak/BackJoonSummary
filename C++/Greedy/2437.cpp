#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define LMIT 1000001

bool comp(char a, char b)
{
    return int(a) == int(b) ? true : false;
}
int min(int &a, int &b)
{
    return a < b ? a : b;
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N = 0;
    cin >> N;
    int input[1000];
    for (size_t i = 0; i < N; i++)
    {
        cin >> input[i];
    }
    sort(input, input + N); //오름 차순 정렬 후
    int sum = 0;            //  sum: sum까지 추로 만들 수 있다 .
    for (size_t i = 0; i < N; i++)
    {
        if (sum + 1 < input[i])
            break;       //만약 현재 추가하련느 추의 무게가, 누적합 sum +1 보다 클 경우 ,  sum+1 은 측정이 불가하다는 뜻
        sum += input[i]; //위에 걸리지 않았다면 누적합을 증가
    }

    cout << sum + 1 << "\n";
}
