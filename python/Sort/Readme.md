#   Sort
-   countingSort.py
    -   enumerate(list,tuple,string) -> index와 value반환 for문에서 반복문 시 둘다 얻을 수 있음
-   2108.py
    -   sorted(정렬할 객체,key=정렬기준) ,key= lamda 변수명(이 변수는 sorted의 첫번째 인자인 정렬할 객체를 가르킨다)
    -   lamda x:x를 이용한 정렬 기준, ex) lamda x:(x[1],-x[0])   x[1]로 오름차순 한 후 ,x[0]으로 내림차순 한다(-는 내림차순 의미)