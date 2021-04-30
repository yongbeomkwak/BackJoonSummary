#include <cstdio>
#include <stack>
#include <cmath>

using namespace std;
void move(const int &  start,const int &  dest) //경로 출력 함수
{
  printf("%d %d\n",start,dest);
}

void hanoi(int N,const int & start ,const int &  via,const int &  dest)
{
  //N=옮길 원판으 갯수
  //start=출발지
  //via=경유지
  //dest=목적지 
 if(N==1)  //N=1 이라는 소리는 다음 단계가 목적지라는 뜻 
 {
   move(start,dest);
 }
 else
 {
   //1 에서 출발하여  3을 갈 때 2를 거쳐야함 
   hanoi(N-1,start,dest,via);  //그렇다면 1에서 출발하여 먼저 3을 경유하여 2를 가야함  
   move(start,dest); //디음 코드에서 경유지에 있던 원판을 도착지에 덮어 놓기 위해서 자기보다 큰 원판을 미리 갔다 놓음 
   hanoi(N-1,via,start,dest); 
   //이후 경유지였던 2가 출발지가 되고  도착지는 그대로 3이 되고 원래 출발지였던 1이 경유지가 됨
 }
  
}

int main()
{
 int N=0;
  scanf("%d",&N);
  printf("%d\n",int(pow(2,N))-1);// 최단 횟수는 2^n -1 이다 
  hanoi(N,1,2,3); //N의 원판을 1기둥을 시작,2기둥을 경유,3기둥음 도착지로 구한다
}