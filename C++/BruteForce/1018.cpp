#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
   char B[][8]={ //Black으로 시작하는 8X8
  {'B','W','B','W','B','W','B','W'},
  {'W','B','W','B','W','B','W','B'},
  {'B','W','B','W','B','W','B','W'},
  {'W','B','W','B','W','B','W','B'},
  {'B','W','B','W','B','W','B','W'},
  {'W','B','W','B','W','B','W','B'},
  {'B','W','B','W','B','W','B','W'},
  {'W','B','W','B','W','B','W','B'}
  };
  char W[][8]={// White로 시작하는 8X8
  {'W','B','W','B','W','B','W','B'},
  {'B','W','B','W','B','W','B','W'},
  {'W','B','W','B','W','B','W','B'},
  {'B','W','B','W','B','W','B','W'},
  {'W','B','W','B','W','B','W','B'},
  {'B','W','B','W','B','W','B','W'},
  {'W','B','W','B','W','B','W','B'},
  {'B','W','B','W','B','W','B','W'},
  };
    int M,N=0; //가로X세로
  scanf("%d %d",&M,&N);
  char **in=new char*[M];
  for(int i=0;i<M;i++) //2차원 배열 만들기
    {
      in[i]=new char[N];
    }
  for(int i=0;i<M;i++) //입력 횟수는 행의 반복 횟수와 같다
    {
      string a; //한줄입력 
      cin >> a;
      
      for(int j=0;j<N;j++)
        {
           in[i][j]=*(a.begin()+j); //한줄 입력받은 문자열을 문자하나하나로 해당 배열 위치에 넣어줌
         
        }
    }
  int end_row=M-8; //남은행이 8보다 작으면 돌릴필요없음
  int end_col=N-8; //남은열이 8보다 작으면 돌릴필이없음
  // 접근 반복문 끝을 나나탬
  int count=9999;  //초기 카운트값을 높게 설정 (최소 값을 구하는 거므로)

  for(int i=0;i<=end_row;i++) 
    {
      int j=0;  //모든 행과 모든 열을 반복하기위해 새로운 행이되면 새로운 열로 돌아가기위함
      while(j<=end_col) //j가 end_col 이상 되면 다시 0으로 초기화 하기위해 바깥의 for문으로 나감
        {
        int prev_count=0; // 이번 결과를 저장할 값
        int prev_count_black=0; //B로 시작하는 8X8로 비교했을 때 값
        int prev_count_white=0; //W로 시작하는 8X8로 비교했을 때 값
          for(int p=i;p<i+8;p++) //현재 위치(행)로 부터 8번 반복
            {
              for(int k=j;k<j+8;k++) //현재 위치(열)로 부터 8번 반복
                {
                  if(in[p][k]!=B[p-i][k-j]) //만약 입력받은 배열의 8X8과 미리만든 체스판 B와 위치 비교했는데 값이 다르면
                  {
                    prev_count_black++; //Black 변수에 count
                  }
                }
            
              }
            for(int p=i;p<i+8;p++)
            {
              for(int k=j;k<j+8;k++)
                {
              
                  if(in[p][k]!=W[p-i][k-j])
                  {
                    prev_count_white++; //White 변수에 count
                  } 
                }
            
              }

          if(prev_count_black>prev_count_white) //black count 크면 
          {
            prev_count=prev_count_white; // white count를 이번 반복의 최종값
          }
          else
          {
            prev_count=prev_count_black; //아니면 black count를 이번 반복의 최종값으로
          }
          if(count>prev_count) //count 값과 이번 최종값 비교시 count가 크면
          {
            count=prev_count; //최솟값 변경
          }
          j++;
        }
    }
  printf("%d",count);
  
  
}