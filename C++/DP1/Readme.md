#   DP

-   1.  11051.cpp
    -   이항계수, 파스칼의 법칙

-   2. 1005.cpp
    -   위상정렬(큐 사용 및 진입차선 inDegree 생각)
-   3.  10942.cpp
    -   회문(펠린드롬)(Palindrome)

-   4.  2098.cpp
    -   TSP(Traveling Salesman problem),외판원 순환문제
    -   [BitMask 사용](https://boycoding.tistory.com/163)

-   5.  14226.cpp
    -   BFS(Breadth-First Search,너비우선탐색)
    -   [BFS](https://gmlwjd9405.github.io/2018/08/15/algorithm-bfs.html)
    -   특징
        -   BFS는 재귀적으로 동작하지 않는다.
        -   이 알고리즘을 구현할 때 가장 큰 차이점은, 그래프 탐색의 경우 어떤 노드를 방문했었는지 여부를 반드시 검사 해야 한다는 것이다.
        -   이를 검사하지 않을 경우 무한루프에 빠질 위험이 있다.
        -   BFS는 방문한 노드들을 차례로 저장한 후 꺼낼 수 있는 자료 구조인 **큐 Queue**를 사용한다. 즉, 선입선출(FIFO) 원칙으로 탐색
        -   일반적으로 큐를 이용해서 반복적 형태로 구현하는 것이 가장 잘 동작한다.
        -   ‘Prim’, ‘Dijkstra’ 알고리즘과 유사하다.
