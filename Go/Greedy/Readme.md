
# Greedy
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