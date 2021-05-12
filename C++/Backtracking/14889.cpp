#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 21
int Tgap=987654321;
int s[MAX][MAX];// 선수정보 담고있음
bool existTeam[MAX]; // 모두 false로 초기화됨
using namespace std;
int memberNum=0;
//Run: F5 + Shift

void DFS(int nowPlayer,int memberCount){ //nowPlayer->현재 플레이어번호,memberCount 지금까지 영입을 끝낸 수 
    if((memberNum/2)==memberCount){  //현재까지 영입을 끝낸 수가 전체 멤버 수의 절반이 된다면, 팀이 정확이 양분됨
        vector<int> team_star,team_link; //star팀과 link 팀생성
        
        for(int i=0;i<memberNum;i++){ //
            if(existTeam[i]) team_star.push_back(i); //밑에 for문에서 existTeam True일 시 star 팀에 넣고
            else team_link.push_back(i); //아니면 link 팀에 , 밑에 existTeam 상태 변경을 1부터 접근 하기 때문에 index 0인 인원은 항상 false,즉 link 팀이 된다
        }

        int star_teamPoint=0,link_teamPoint=0;
        for(int i=0;i<team_star.size();i++){
            for (int j = i+1; j < team_star.size(); j++) //i보다 항상 앞서서 검사
            {
                int star_i=team_star[i],star_j=team_star[j];
                int link_i=team_link[i],link_j=team_link[j];
                star_teamPoint+=s[star_i][star_j]+s[star_j][star_i]; //각각 포인트 더하기
                link_teamPoint+=s[link_i][link_j]+s[link_j][link_i]; //각각 포인트 더하기
            }
            
        }
        Tgap=min(Tgap,abs(star_teamPoint-link_teamPoint)); //현재값과 ,방금 계산한 차이값의 절대값을 비교 

    }
    else{
        for(int i=nowPlayer+1;i<memberNum;i++) //인덱스로 접근하기 때문에 1~N-1 까지,0번째 인덱스는 항상 star팀
        {
            if(!existTeam[i]){ //만약 false 이면
                existTeam[i]=true; //true로 바꾸고
                DFS(i,memberCount+1); //완전 탐색
                existTeam[i]=false;
            }
        }
    }
}

int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> memberNum;

    for (int i = 0; i < memberNum; i++)
    {
        for (int j = 0; j < memberNum; j++)
        {
            cin >> s[i][j];
        }
    }

    DFS(0,0);
    cout << Tgap <<"\n";
    
}