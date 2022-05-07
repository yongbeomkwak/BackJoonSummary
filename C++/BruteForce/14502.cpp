#include <bits/stdc++.h>

using namespace std;
#define MAX 10
typedef struct _POINT{
    int x,y;
}point;

int gmap[MAX][MAX],copyed[MAX][MAX];
int n,m;
int ret=0;
vector<point> viruses;
bool visited[MAX][MAX];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};

int countZero()
{
  int zero=0;
  for(int i=0;i<n;i++)
  {
      for(int j=0;j<m;j++)
      {
          if(copyed[i][j]==0) zero++;
      }
  }
  return zero;
}

void spreadVS()
{
    memset(visited,false,sizeof(visited)); // 방문 배열 초기화 
    
    queue<point> q;
    
    for(point& p:viruses)
    {
        visited[p.x][p.y]=true; //바이러스는 방문처리
        q.push({p.x,p.y}); //바이러스 좌표를 큐에 삽입 
    }
    
    //배열 복사하기
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            copyed[i][j]=gmap[i][j];
        }
    }
    
    while(!q.empty())
    {
        int x=q.front().x;
        int y=q.front().y;
        q.pop();
        
        for(int i=0;i<4;i++)
        {
            const int nx=x+dx[i];
            const int ny=y+dy[i];
            if(nx<0||ny<0||nx>=n||ny>=m) continue; //범위를 넘었거나 
            if(copyed[nx][ny]!=0 || visited[nx][ny]==true) continue; //해당 지역이 빈 곳 또는 방문한 곳이면 다시
            
            copyed[nx][ny]=2; //바이러스 퍼짐
            visited[nx][ny]=true; //방문
            q.push({nx,ny}); //새로운 바이러스 지역 넣기
            
        }
    }
    
}

void setWall(const int cnt)
{
    if(cnt==3) //3개 세웠으면 countZero
    {
        spreadVS();
        ret=max(ret,countZero());
        return;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(gmap[i][j]==0)
            {
                gmap[i][j]=1; //벽 세우기 
                setWall(cnt+1);
                gmap[i][j]=0;
            }
        }
    }
    
    
}

int main()
{
    cin >> n >> m;
    
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >>gmap[i][j];
            if(gmap[i][j]==2) viruses.push_back({i,j});// 바이러스 좌표 저장 
        }
    }
    setWall(0); 
    
    cout <<ret;
    return 0;
}
