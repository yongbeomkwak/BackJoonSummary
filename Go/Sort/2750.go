package main

import (
	"fmt"
	"sort"
)

func main() {
	//reader := bufio.NewReader(os.Stdin)
	num := 0
	fmt.Scan(&num)
	in_list := make([]int, 0)
	for i := 0; i < num; i++ {
		temp := 0
		fmt.Scan(&temp)
		in_list = append(in_list, temp)
	}
	sort.Slice(in_list, func(i, j int) bool {
		if in_list[i] < in_list[j] {
			return true
		}
		return false
	})

	for _, val := range in_list {
		fmt.Println(val)
	}
}
