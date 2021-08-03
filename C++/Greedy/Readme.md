# Greedy
-   1339.cpp
    -   based range for 문 문법있음
        -   for(타입 변수명:반복가능 객체){ }  반복가능객체->string,vector..
    -   기본 for문과 다른점은 index를 사용할 수 없음과 값 수정이 안됨,해당 변수에 복사하는 방식이므로)
    -   복사를 원치 않는 다면 &(레퍼런스 참조자 이용) (실제 값 변경 됨)
        - for(타입& 변수명:반복가능 객체){}   
-   1715.cpp
    -   PriorityQueue 사용법 있음

-   1202.cpp
    -   PriorityQueue 에 대한 비교 구조체 생성 및 정리
    -   오름차순 내림차순은 ,top을 기준이기 때문에 비교구조체 operator의  부등호 방향을 신경써라 !!

-   1543.cpp 
    -   char 배열 및 string 입력 및 비교차이
    -   char 배열 공백 포함 한줄 입력 시 cin.getline(arr,size)
    -   string 공백 포함 한줄 입력 시 getline(cin,str)
    -   비교 시
        -   string은 str1.compare(str2)
        -   char 배열은 , strcmp(arr1,arr2) or strncmp(arr1,arr2)
-   10775.cpp
    -   [UnionFind 알고리즘](https://ip99202.github.io/posts/%EC%9C%A0%EB%8B%88%EC%98%A8-%ED%8C%8C%EC%9D%B8%EB%93%9C(Union-Find)/#:~:text=%EC%9C%A0%EB%8B%88%EC%98%A8%20%ED%8C%8C%EC%9D%B8%EB%93%9C%EB%8A%94%20%EA%B7%B8%EB%9E%98%ED%94%84%20%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98,%EC%B0%BE%EB%8A%94%20Find%EC%97%B0%EC%82%B0%EC%9C%BC%EB%A1%9C%20%EC%9D%B4%EB%A3%A8%EC%96%B4%EC%A7%84%EB%8B%A4.) 이용 
    -   *유니온 파인드*는 **그래프 알고리즘**으로 두 노드가 같은 그래프에 속하는지 판별하는 알고리즘이다.
    -   **서로소 집합**, **상호 베타적 집합**(Disjoint-Set)으로도 불린다.
    -   노드를 합치는 Union연산과 노드의 루트 노드를 찾는 Find연산으로 이루어진다.
    -   트리 구조로 이루어진 자료구조 중 한가지로 생각되기도 한다.
- 15904.cpp
  - string::find 설명   
- memset
-   memset함수는 어떤 메모리의 시작점부터 연속된 범위를 어떤 값으로(바이트 단위) 모두 지정하고 싶을 때 사용하는 함수이다. (초기화 할 때)\
-   int일 경우 0 또는 -1 만 가능 , 1 안되더라 
-   char 는 다 되더라 'A' ~ 'Z' S


 기본 함수 구조 및 매개변수

 void * memset ( void * ptr, int value, size_t num );

 ptr: 채우고자 하는 메모리의 시작 포인터(시작 주소)

 value: 메모리에 채우고자하는 값. int형이지만 내부에서는 unsigned char(1 byte)로 변환되어서 저장된다.

num: 채우고자 하는 바이트의 수. 즉, 채우고자 하는 메모리의 크기
    
