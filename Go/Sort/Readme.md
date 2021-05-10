#   Sort
-   mergeSort.go
    -   merge 함수에서, python문버인 slice 이용하여 많은 오류가 남 ex) temp_list=raw_list[0:end+1]
    -   append로 수정함, 이유는 raw_list가 업데이트 될 때마다 변경되므로 사용할 수 없음
- 2108.go
  - map 과 slice를 통해 Sort하기, sort.Slice(정렬할 객체,익명함수 func(i,j)bool{})
  - 익명함수를 이용하여 정렬 방법 정의 여기서 i는 현재 인덱스,j는 다음 index를 가르킴