#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 500001
typedef pair<int, int> pai;
typedef vector<int>::iterator iter;

int max(const int &a, const int &b)
{
    return a > b ? a : b;
}
int min(const int &a, const int &b)
{
    return a < b ? a : b;
}

bool comp(const int &a, const int &b)
{
    return a > b;
}
int N;
int main()
{
    enum
    {
        PALIN = 0,
        SEMI_PALIN,
        NOT_PALIN
    };

    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;

    for (int t = 0; t < N; t++)
    {
        char str[100001];
        cin >> str;
        int ans = PALIN;
        for (int i = 0, j = strlen(str) - 1; i < j; i++, j--)
        {
            if (str[i] == str[j])
            {
                continue;
            }

            if (str[i + 1] != str[j] && str[i] != str[j - 1]) //왼쪽 다음 꺼와, 오른쪽 다음 꺼를 현재와 비교를 했을 때 만약 둘다 틀리다면
            {
                ans = NOT_PALIN;
                break;
            }
            bool isPALIN = false; //일단 위 검사를 통과했다는 것은 완전한 회문은 될 수 없다 ,그러면 SEMI,인지 NOT인지 한번더 검사해야함

            for (int k = 0; k < 2 && isPALIN == false; k++)
            {
                int start = i;
                int end = j;
                k == 0 ? start++ : end--; // k==0 처음은 , 왼쪽(start) 을 한번 당겨서 진행 ,k==1 두번째는 오른쪽을 당김

                isPALIN = true;
                for (int a = start, b = end; a < b; a++, b--) // 처음에는 위에서 왼쪽을 당긴 후  돌고, 2번 째는 오른쪽을 당겨서 진행
                {
                    if (str[a] != str[b]) //만약 위에서 이렇게 당겼는데도  다르다면, 완전한 NOT_PLAIN이 된다
                    {
                        isPALIN = false;
                        break;
                    }
                }
            }
            ans = isPALIN ? SEMI_PALIN : NOT_PALIN; //여전히 true 면  처음에 한번만 틀렸다는 것이니 SEMI,false면 2 번 검사 모두 불통  NOT
            break;
        }
        cout << ans << "\n";
    }
}
