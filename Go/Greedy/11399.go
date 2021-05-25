package main

import (
	"fmt"
	"sort"
)

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	N := 0
	fmt.Scan(&N)
	time := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&time[i])
	}
	sort.Slice(time, func(i, j int) bool {
		return time[i] < time[j]
	})

	count := make([]int, N)
	count[0] = time[0]
	for i := 1; i < N; i++ {
		count[i] = count[i-1] + time[i]
	}
	sum := 0
	for i := 0; i < N; i++ {
		sum += count[i]
	}
	fmt.Println(sum)

}
