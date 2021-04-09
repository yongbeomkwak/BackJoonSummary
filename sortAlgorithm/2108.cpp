#include <iostream>
#include <cstdio>
#include <algorithm> //max_element를 위한
#include <cmath>
#include <map>
#include <vector>
using namespace std;

bool sortByVal(const pair<int, int> &a, //최빈값을 찾기 위함
               const pair<int, int> &b)
{                            //first는 해당 숫자 ,second 는 빈도 수
    if (a.second > b.second) //빈도수가 크게 정렬
    {
        return true;
    }
    else if (a.second == b.second) //만약 빈도수가 같으면
    {
        if (a.first < b.first) //숫자가 작게 정렬
        {
            return true;
        }
    }

    return false;
}
bool sortByKey(const pair<int, int> &a, //중간값을 찾기 위한 정렬
               const pair<int, int> &b)
{
    if (a.first < b.first) //오름차순 정렬
    {
        return true;
    }
    return false;
}
int main()
{

    unsigned int N = 0;
    int temp = 0;
    scanf("%d", &N);
    map<int, int> countMap; //Map 생성

    int max = -9999;             //초기 최대값
    int min = 9999;              //초기 최솟값
    int mode = 0;                //최빈값
    int count_mid = (N / 2) + 1; //중앙값 위치는 전체입력 갯수를 2로 나눈값 (인덱스로 접근할 것이므로 +1 안함)
    double Amean = 0;            //산술평균 (모든 수의 합 /수의 개수)
    int mid = 0;                 //중앙값

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &temp); //입력받음
        Amean += temp;      //모든 수의 합

        if (countMap.count(temp) == 0) //키가 없을 시 0이 나옴
        {
            countMap.insert(pair<int, int>(temp, 1)); //키와 값 추가 (pair객체 사용해야 함)
        }
        else
        {
            countMap[temp]++; // 만약 존재시 count 하여 올림
        }
    }

    map<int, int>::iterator it = countMap.begin();
    vector<pair<int, int> > vec;
    for (auto k = it; k != countMap.end(); k++) //반복
    {
        //반복 하면서 pair객체 first(key)와 second(value)를 만든후 백터로 넣음
        vec.push_back(make_pair(k->first, k->second));
        int key = k->first;    //해당 숫자
        int value = k->second; // 빈도 수

        if (key > max) //최대값
        {
            max = key;
        }
        if (key < min) //최솟값
        {
            min = key;
        }
    }
    sort(vec.begin(), vec.end(), sortByVal); //먼저 최빈값을 위한 정렬

    mode = vec[0].first;                //최빈값을 넣고
    if (vec[0].second == vec[1].second) //만약 다음값과 빈도수가 같으면
    {
        mode = vec[1].first; // 두번 째로 작은 값을 넣음
    }

    sort(vec.begin(), vec.end(), sortByKey); //중앙값을 위한 정렬
    int count = 0;                           // 중앙값을 찾아갈 값
    for (auto k = vec.begin(); k != vec.end(); k++)
    {
        count += k->second;
        if (count >= count_mid) //해당 중앙값 위치를 지나치거나 도착하면
        {
            mid = k->first; //그 값을 넣어줌
            break;
        }
    }

    int round_mean;

    if (Amean < 0) //만약 현재까지 더한 값이 0보다 작으면 즉, 음수이면
    {
        Amean = Amean / N;    //나눈후
        Amean = round(Amean); //반올림
        round_mean = Amean;   // int형으로 넣음
    }
    else
    {
        Amean = round(Amean / N); //수의 개수를 첫째 자리에서 반올림
        round_mean = Amean;       //그대로 넣음
    }

    printf("%d\n%d\n%d\n%d", round_mean, mid, mode, (max - min)); //출력
}
