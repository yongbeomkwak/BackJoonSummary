
#include <bits/stdc++.h>

using namespace std;

#define MAX 100001
int d,k;
int arr[MAX]={0,};
int A[31];
int B[31];
int main()
{
    cin >> d >> k;
    
    A[1]=1; // 
    B[2]=1; // 
    
    
    for(int i=3;i<=d;i++)
    {
        A[i]=A[i-1]+A[i-2];
        B[i]=B[i-1]+B[i-2];
    }
    
    
    for(int i=1;i<=k;i++)
    {
        int rest=k-i*A[d]; //나머지 떡
        
        if(rest%B[d]==0)
        {
            cout << i <<endl << rest/B[d];
            break;
        }
        
    }
}
