#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<pair<int, int> > vec(N); //N길이 백터 생성 first->data,second -> 초기 인덱스
    vector<int> answer(N);          //N 길이의 벡터 생성(결과 값 벡터)

    for (int i = 0; i < N; ++i)
    {
        cin >> vec[i].first; /// 데이터 삽입
        vec[i].second = i;   //인덱스 삽입
    }
    //<data,index>
    sort(vec.begin(), vec.end()); // 내림 차순 정렬

    int ct = 0;
    for (int i = 0; i < N; ++i)
    {
        int idx = vec[i].second; //정렬된(오름차순) 벡터안의 인덱스값 접근
        int temp = ct;           //최소 값으로부터 거리

        answer[idx] = temp; //정답 벡터에 초기 인덱스 값에
        ct++;               //
                            // 정렬된 배열값
                            // temp=0 일 때
                            // 1(a) 1(b) 1(c) 2(d) 현재 1(a) 가 i 면 i+1 은 1(b)
                            //  둘 값이 같기 때문에 1(b)가 있는 인덱스에 대한 정답 벡터에도 0(temp)를 넣음
                            // 또 다음은 1(b) 와 1(c)가 같기 때문에 똑같이 0(temp)를 넣어줌
                            // 1(c) 와 2(d)가 다르기 때문에 다시 for문으로 돌아간다
        while (i < N && vec[i].first == vec[i + 1].first)
        {
            //만약 정렬된 배열 중 현재값이 다음값과 같다면
            // 1 1 2
            ++i;                 // 그 다음 값으로 이동하여
            idx = vec[i].second; // 이동한 값(다음 값)의 인덱스를 얻은후
            answer[idx] = temp;  //정답 배열에 이전값과 같은 거리를 넣어줌
        }
    }

    for (auto a : answer) //출력
        cout << a << " ";
}