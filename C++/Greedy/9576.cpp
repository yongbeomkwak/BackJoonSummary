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
typedef struct _RANGE
{
    int s, e;
} Range;
int N = 0;

bool comp(const Range &a, const Range &b)
{
    if (a.e < b.e)
    {
        return true;
    }
    else if (a.e == b.e)
    {
        return a.s < b.s;
    }
    return false;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T, N, M = 0;
    cin >> T;
    while (T--)
    {
        cin >> N >> M;
        int a, b = 0;
        int ans = 0;
        Range book[1001];
        int posi[1001] = {0}; // 해당 책을 줬냐 안줬냐 판별
        for (int i = 0; i <= 1000; i++)
        {
            posi[i] = 0; // 처음에는 안줬으므로 0으로 판별
        }

        for (int j = 0; j < M; j++)
        {
            cin >> book[j].s >> book[j].e; // 시작 점 끝 점 받은 후
        }
        sort(book, book + M, comp); // 끝 점을  기점으로 정렬

        for (size_t k = 0; k < M; k++) //학생 수 만큼 순회
        {
            for (size_t j = book[k].s; j <= book[k].e; j++) // 해당 학생이 들고 있는 시작 점 부터 끝 점 까지, 반복하여
            {
                if (posi[j] == 0) //아직 주지 않은 책을
                {
                    posi[j] = 1; // 준다
                    ans += 1;    // 책을 받은 학생 수 증가
                    break;       // 줬으므로 반복 종료
                }
            }
        }
        cout << ans << "\n"; // 학생 수 출력
    }
}
