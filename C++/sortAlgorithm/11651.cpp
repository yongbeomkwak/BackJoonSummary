#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

bool comp(const pair<int,int> & a,const pair<int,int> &b)
{
  //pair 객체를 받아 
  if(a.second<b.second) //secnod 오름차순 
  {
    return true;
  }
  else if(a.second==b.second) //만약 같으면 first로 오름차순
  {
    return(a.first<b.first);
  }
  return false;
}

int main() {
  int tc=0;
  vector<pair<int,int>> v; //pair 객체로 저장
  int a,b=0;
  scanf("%d",&tc);
  for(int i=0;i<tc;i++)
    {
      scanf("%d %d",&a,&b);
      pair<int,int> p(a,b);
      v.push_back(p);
    }
  sort(v.begin(),v.end(),comp);
  for(auto k=v.begin();k!=v.end();k++)
    {
      printf("%d %d\n",k->first,k->second);
    }
  
}