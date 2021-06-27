#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
int Gate[100001]; //부모 배열
int Pa[100001];

int findRoot(int &n)
{
    //보통 n에 해당하는 Gate[n]이 부모를 가르킨다
    if (Gate[n] == n) // 인덱스에 해당 하는 값과 인덱스 값이 같으면  부모
    {
        return n; // 부모
    }
    else //만약 같지 않다면, 부모가 아니라는 , 부모를 찾기위해 재귀적 호출 ,제일 위인 root 를 찾기 전까지 계속 재귀
    {
        return Gate[n] = findRoot(Gate[n]);
    }
}

void Union(int a,int b)// b 노드를 a자식으로 합침 
{
    a=findRoot(a); //부모가 될 
    b=findRoot(b); // 자식이 될 
    Gate[b]=a; //b 인덱스에 해당하는 부모를 a로 설정 
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int G, P;
    cin >> G;
    cin >> P;

    int ans = 0;
    for (int i = 0; i <= G; i++)
    {
        Gate[i] = i; //각 게이트의 부모를 인덱스와 동일하게 해줌
    }

    for (int i = 1; i <= P; i++)
    {
        int num = 0;
        cin >> num;
        Pa[i] = num;
    }
    for (int i = 1; i <= P; i++)
    {
        int k=findRoot(Pa[i]); //i 인덱스에 Root 찾기 
        if(k==0) break; // 못 찾음 
        Union(k-1,k);  //k의 부모를 k-1로 설정(게이트 번호가 높은데에서 낮은 순으로 채움 )
        ans++;
    }

    //UnionFind Algorithm

    cout << ans;
}
