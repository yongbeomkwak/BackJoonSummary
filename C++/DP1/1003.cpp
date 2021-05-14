#include <iostream>
#include <cstdio>
using namespace std;
long long memo[50] = {
    0,
    1,
};
long long fibo(int N)
{
    if (N == 0 || N == 1)
        return memo[N]; //이미 초기화 시 값이 있음
    else if (memo[N] == 0)
        memo[N] = fibo(N - 1) + fibo(N - 2);
    return memo[N];
}

// N=        0 1 2 3 4 5
//memo       0 1 1 2 3 5
// 0호출 패턴  1 0 1 1 2 3 5
// 1호출 패턴  0 1 1 2 3 5
// N=0일 때 제외 하고  보면 0호출은 memo[N-1],1호출 memo[N]을 가르킨다
// 그러므로 cout << fibo(n-1) fibo(n) 이된다
int main()
{

    int tc = 0;
    scanf("%d", &tc);
    int n = 0;
    for (int i = 0; i < tc; i++)
    {
        cin >> n;
        if (n == 0)
        { //0 일 때는 0호출 1번,1호출 0번
            cout << "1 0"
                 << "\n";
        }
        else
        {
            cout << fibo(n - 1) << ' ' << fibo(n) << "\n";
        }
    }
}