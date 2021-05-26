#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>

#define LMIT 100001
#define MAX 1000000000
long long grd[LMIT];
long long dis[LMIT];
using namespace std;
int main()
{
    int N = 0; //도시 개수
    int L = 0; //총 거리 합 
    int min = MAX; //기름값 최소값 
    int mindex = 1; //기름값 최소값 도시를 가르키는 인덱스 
    long long result = 0; //결과
    scanf("%d", &N); //도시 개수 입력 받기 
    for (int i = 1; i < N; i++) 
    {
        scanf("%lld", &dis[i]); //거리 입력 받기
        L += dis[i]; //거리 총합 
    }
    for (int i = 1; i < N; i++)
    {
        scanf("%lld", &grd[i]);
        if (min > grd[i])
        {
            min = grd[i]; //최소 비용 업데이트
            mindex = i;//최소 비용을 갖는 도시 업데이트
        }
    }

    if (mindex == 1) //만약 최소 인덱스가 1일 경우 , 출발점 부터 거리만큼 만땅 기름을 넣으면 됨
    {
        result = L * grd[1]; // 거리 총합*출발점 기름값
    }
    else
    {
        int mincost = grd[1]; // 첫 최소 비용은 출발점 기름값
        result = mincost * dis[1]; //그러므로 결과 변수에 기름값*첫번째 거리 저장 
        L -= dis[1]; // 첫번째 거리를 지나갔으므로 그만큼 빼줌 
        for (int i = 2; i < mindex; i++) //위에서 찾은 최소 비용을 갖는 도시전 까지만 반복문을 돔
        {
            if (mincost < grd[i]) //만약 과거 최소 비용이 현재 도시의 기름값보다 작을 경우 이번 도시에서는 기름 넣지않고 과거 도시 비용으러 넣음 
            {
                result += mincost * dis[i]; // 최소비용 * 이번 도시 거리 
                L -= dis[i]; //거리 총합에서 빼줌
            }
            else //그렇지 않으면 이번도시 기름값으로 넣음 
            {
                mincost = grd[i]; //최소 기름값을 이번 도시 기름값으로 초기화 
                result += mincost * dis[i];// 결과 더 해줌 
                L -= dis[i]; //거리 종합에서 빼줌
            }
        }
        result += grd[mindex] * L; //for문을 빠져 나왔다는 것은 최소 비용 도시에 도착, 그러므로 최소 비용도시 * 남은거리를 더 해줌 
    }
    printf("%lld", result); //출력 
}