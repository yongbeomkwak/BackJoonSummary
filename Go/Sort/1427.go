package main

import (
	"fmt"
	"sort"
	"strconv"
)

func main() {
	//reader := bufio.NewReader(os.Stdin)
	num := ""
	fmt.Scan(&num)
	num_slice := make([]int, 0)
	for _, val := range num {
		temp, _ := strconv.Atoi(string(val))
		num_slice = append(num_slice, temp)
	}
	sort.Slice(num_slice, func(i, j int) bool {
		return num_slice[i] > num_slice[j]
	})

	for _, val := range num_slice {
		fmt.Print(val)
	}
}
