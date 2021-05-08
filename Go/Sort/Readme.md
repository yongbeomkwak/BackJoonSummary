#   Sort
-   mergeSort.go
    -   merge 함수에서, python문버인 slice 이용하여 많은 오류가 남 ex) temp_list=raw_list[0:end+1]
    -   append로 수정함, 이유는 raw_list가 업데이트 될 때마다 변경되므로 사용할 수 없음