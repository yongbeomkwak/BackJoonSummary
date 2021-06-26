#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    char doc[2501];
    char word[51];
    size_t answer = 0;

    cin.getline(doc, 2501); // 문서 입력
    cin.getline(word, 51);  // 단어  입력
    size_t i = 0;
    while (i != strlen(doc)) //문서 끝을 넘어가면 종료
    {
        for (size_t j = 0; j < strlen(word); j++)
        {

            if (i + j >= strlen(doc)) //만약 현재 문서 위치 + 단어 위치가 , 문서의 범위를 벗어 났다면, 더 이상 단어 완성은 힘듬,
            {                         //Index 범위 초과 방지
                i++;                  //i 를 증가시켜 while문을 빠져나가게 함
                break;
            }
            else //아닐 경우 비교
            {
                if (doc[i + j] != word[j]) //만약 현재 문서가 가르키는 글자와 단어 글자가 다를 경우 , 문서 검색 시작점을 한 칸 옮김
                {
                    i++; // 한칸 옮김 (다음 i 시작점 바로 오른  쪽)
                    break;
                }
                else //만약 같을경우
                {
                    if (j == strlen(word) - 1) // 단어 끝까지 왔다면
                    {
                        answer++;        // 값을 증가 시키고
                        i = (i + j + 1); // 문서가 가르키는 다음 위치를 현재 위치(i)+j(단어 끝 위치) +1(겹치지 않기 위해)
                        //doc:abcabc
                        //word:abc
                        //i는 첫 a 위치 0
                        //여기서 아마 j는 c의 인덱스 2 가 됨
                        //두번 째 a 위치 3 이 다음 i(시작 점이) 되어야 함
                        // i(0)+j(2)+1 = 3  = 다음 i
                    }
                }
            }
        }
    }

    cout << answer; //출력
}