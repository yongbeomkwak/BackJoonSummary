package main

import (
	"fmt"
	"sort"
)

func countingSort(raw_list []int, max_val int) []int {

	result := make([]int, max_val+1)

	for _, val := range raw_list {
		result[val]++
	}
	return result
}

func main() {
	//reader := bufio.NewReader(os.Stdin)
	num := 0
	fmt.Scan(&num)
	in_map := make(map[int]int, 0)
	//다중 정렬로 정렬해보기
	for i := 0; i < num; i++ {
		key := 0
		fmt.Scan(&key)
		val, exists := in_map[key]
		if !exists { //존재 안할 시
			in_map[key] = 1
		} else {
			in_map[key] = val + 1
		}
	}
	final_slice := make([][]int, 0)
	for key, val := range in_map {
		temp_slice := make([]int, 0)
		temp_slice = append(temp_slice, key)
		temp_slice = append(temp_slice, val)
		final_slice = append(final_slice, temp_slice)
	}
	sort.Slice(final_slice, func(i, j int) bool {
		if final_slice[i][1] > final_slice[j][1] {
			return true
		} else if final_slice[i][1] == final_slice[j][1] {
			return final_slice[i][0] < final_slice[j][0]
		} else {
			return false
		}
	})
	fmt.Println(final_slice)
}
