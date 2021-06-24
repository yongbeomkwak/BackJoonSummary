# Greedy
-   1339.cpp
    -   based range for 문 문법있음
        -   for(타입 변수명:반복가능 객체){ }  반복가능객체->string,vector..
    -   기본 for문과 다른점은 index를 사용할 수 없음과 값 수정이 안됨,해당 변수에 복사하는 방식이므로)
    -   복사를 원한다면 &(레퍼런스 참조자 이용)
        - for(타입& 변수명:반복가능 객체){}   
-   1715.cpp
    -   PriorityQueue 사용법 있음

-   1202.cpp
    -   PriorityQueue 에 대한 비교 구조체 생성 및 정리
    -   오름차순 내림차순은 ,top을 기준이기 때문에 비교구조체 operator의  부등호 방향을 신경써라 

- memset
-   memset함수는 어떤 메모리의 시작점부터 연속된 범위를 어떤 값으로(바이트 단위) 모두 지정하고 싶을 때 사용하는 함수이다. (초기화 할 때)


 기본 함수 구조 및 매개변수

 void * memset ( void * ptr, int value, size_t num );

 ptr: 채우고자 하는 메모리의 시작 포인터(시작 주소)

 value: 메모리에 채우고자하는 값. int형이지만 내부에서는 unsigned char(1 byte)로 변환되어서 저장된다.

num: 채우고자 하는 바이트의 수. 즉, 채우고자 하는 메모리의 크기
    