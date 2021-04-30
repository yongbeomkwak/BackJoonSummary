#include <iostream>
#include <cstdio>
#include <algorithm>  //max_element를 위한

using namespace std;

#define MAX 10001
int main() {

 unsigned int N=0;
  scanf("%d",&N);
  int arr[MAX]={0};
  int temp=0;
   for(int i=0;i<MAX;i++) //0으로 일단 초기화
    {
      arr[i]=0;
    }
  for(int i=0;i<N;i++)  //카운팅 
    {
      scanf("%d",&temp);
      arr[temp]++; // 해당 숫자를 인덱스로 사용하여 그 값을 1씩 증가
    }
  for(int i=0;i<MAX;i++) //출력
    {
      if(arr[i]!=0) //0이라는 것은 그 자리에 입력이 없었다는 뜻 
      {
         for(int j=0;j<arr[i];j++) //0이 아니면 해당 카운팅 만큼 반복해서 출력
        {
          printf("%d ",i); //해당 숫자를 해당 카운팅 만큼 출력
        }
      }
     
    }


  }
