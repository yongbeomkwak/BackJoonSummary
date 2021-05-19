package main

import (
	"fmt"
	"sort"
)

const LMIT = 1001

var dp [LMIT]int
var in_list [LMIT]int

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	n := 0
	fmt.Scan(&n)
	a_to_b := make([][]int, 0)
	for i := 1; i <= n; i++ {
		a := 0
		b := 0
		temp_slice := make([]int, 0)
		fmt.Scan(&a, &b)
		temp_slice = append(temp_slice, a, b)
		a_to_b = append(a_to_b, temp_slice)
	}

	sort.Slice(a_to_b, func(i, j int) bool {
		if (a_to_b[i][0]) < a_to_b[j][0] {
			return true
		}
		return false
	})

	for i := 0; i < n; i++ {
		dp[i] = 1
	}
	max_line := 0

	for i := 0; i < n; i++ {
		for j := 0; j < i; j++ {
			if a_to_b[i][1] > a_to_b[j][1] {
				dp[i] = max(dp[i], dp[j]+1)
			}
		}
		max_line = max(max_line, dp[i])
	}

	fmt.Println(n - max_line)
}
