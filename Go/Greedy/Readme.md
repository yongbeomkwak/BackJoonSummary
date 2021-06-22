
# Greedy
-   1339.go
    -   Sort 설명 
    -   	sort.Sort(sort.Reverse(sort.IntSlice(alpha))) //내림차순
-   1715.go
    -   Heap을 이용한 PriorityQueue 만들기
        -  Len,Swap,Push,Pop,Less 구현 
    -   interface 및 receiver 정리 
        -   1. (pq PriorityQueue) 를 value receiver 라고 부르고, (pq *PriorityQueue) 를 pointer receiver 라고 부릅니다.

            pointer receiver 를 쓰는 경우는 보통 1) receiver 의 크기가 매우 크거나 2) receiver 의 내용을 바꿔야 할 필요가 있을 때, 이렇게 두 경우일 때가 많습니다.

            PriorityQueue 타입 본체의 크기는 포인터 1개 + int 2개 = 24 byte 이므로 1번은 큰 메리트가 없습니다.

            다만, Push 와 Pop 의 경우 slice 자체의 내용을 수정할 필요가 있기 때문에 pointer receiver 를 사용해야 합니다.

            

            2. interface{} 는 Java 의 Object 타입과 유사합니다. 어떠한 type 의 데이터든 가질 수 있습니다.

            

            3. type assertion 이라고 부릅니다. interface 가 가지고 있는 데이터의 type 이 정말로 *Item 인지 검증하고,

            검증에 성공하면 그 이후로는  *Item 과 동일하게 활용할 수 있습니다 (예를 들어 .data 구조체 필드를 읽고쓰기)

            검증에 실패하면 런타임 에러를 일으킵니다.
 ___
    -   slice 구성요소 및 &(구조체 동적할당)
    1. PriorityQueue 는 slice type 입니다. slice 를 구조체처럼 생각한다면 (배열의 메모리 주소, length, capacity) 로 이루어져 있습니다.

        length 는 "현재"의 데이터 크기, capacity 는 (메모리 재할당 없이) 최대로 커질 수 있는 크기 입니다.

    배열의 element 는 Item 을 가리키는 포인터이고, Item 은 int 하나를 가지고 있지만, slice "구조체"의 일부는 아닙니다.

   
---
    1. item = new(Item); item.data = conv_temp; 라고 생각하시면 됩니다.

    즉, Item 을 동적 할당 하고, 정해진 field 를 초기화 한 다음에, 동적 할당한 메모리 주소를 item 변수에 넣습니다.