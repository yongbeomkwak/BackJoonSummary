#include <bits/stdc++.h>

using namespace std;

#define MAX 21
int n,s;
int arr[MAX];
int ans=0;

void dfs(const int idx,const int sum)
{
    if(idx==n)
    {
        if(sum==s) ans++;
        return;
    }
    
    dfs(idx+1,sum); //이번 인덱스는 넘어감
    dfs(idx+1,sum+arr[idx]); //이번 인덱스 더하기
}
int main()
{
    cin >> n >>s;
    
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    
    dfs(0,0);
    
    if(s==0) ans--;
    
    cout << ans;
}
