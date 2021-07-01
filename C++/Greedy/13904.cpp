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

typedef struct _ASSIGMENT
{
    int d, w;
} Assigment;

bool comp(Assigment &a, Assigment &b)
{
    if (a.w == b.w)
    {
        return a.d < b.d;
    }
    return a.w > b.w;
}

int dayScore[1000 + 1];

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N = 0;
    cin >> N;
    Assigment arr[1000 + 1];
    int result = 0;
    for (size_t i = 0; i < N; i++)
    {
        Assigment s;
        cin >> s.d >> s.w;
        arr[i] = s;
    }
    sort(arr, arr + N, comp);

    for (int i = 0; i < N; i++)
    {
        int day = arr[i].d - 1; //~부터   index가 0부터 시작이므로 4(일)이 3일로 생각한다 (0~3)==(1~4)

        while (1)
        {
            if (dayScore[day] == 0 || day < 0) // 과제를 할 날짜를 찾앗거나(dayScore[day]==0) 또는 못 찾었거나(day<0)
            //이렇게 되면, 데드라인에 딱 맞혀서 Grid하게 한다.
            //arr[i].d =4   -> day =3 일 때 dayScore[3] =0 일 될 것이고, 밑에서 일정을 잡는다
            // 즉 4일 짜리는 0 1 2 3 (3) -> 4번 째 날 한다
            // 만약에 한번 더 4 일 짜리 들어오면 , dayScore[3]이 일정이 있으므로 2 .. 1 .. 0 이런식으로 탐색하며 넣는다
            {
                break;
            }
            day--;
        }
        if (day >= 0) //만약 day가 음수가 아니면, 과제 할 수 있는 일정이 있음
        {
            dayScore[day] = arr[i].w; //해당 과제를(arr[i]) 해당 day에 한다고 일정을 잡는다
        }
    }

    for (int i = 0; i < 1000; i++)
    {
        result += dayScore[i];
    }
    cout << result << "\n";
}
