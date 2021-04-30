#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

bool comp(const int & a,const int &b)
{
  if(a>b)
  {
    return true;
  }
  return false;
}

int main() {
  vector<int> v;
  char a[11]={'0'}; // 초기화 중요
  scanf("%s",&a);
  for(int i=0;i<11;i++)
    {
      if(a[i]) //비어있는 값이 아니면
      {
        v.push_back(a[i]-'0');// char to int 
      }
    }
  sort(v.begin(),v.end(),comp); //내림 차순 정렬
  for(auto k=v.begin();k!=v.end();k++) //출력 
    {
      printf("%d",*k);
    }
  
}