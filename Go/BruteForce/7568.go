package main

import (
	"fmt"
)

func main() {
	//reader := bufio.NewReader(os.Stdin)
	var tc int
	fmt.Scan(&tc)
	var h, w int
	in_list := make([][]int, 0) //2차원 slice
	for i := 0; i < tc; i++ {
		fmt.Scan(&w, &h)
		temp := make([]int, 0)
		temp = append(temp, w)
		temp = append(temp, h)
		in_list = append(in_list, temp)
	}
	result := make([]int, 0)
	for i, curr := range in_list {
		count := 1
		for j, other := range in_list {
			if i != j {
				if curr[0] < other[0] && curr[1] < other[1] {
					count++
				}
			}
		}
		result = append(result, count)
	}

	for _, val := range result {
		fmt.Printf("%d ", val)
	}

}
