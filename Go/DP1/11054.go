package main

import (
	"fmt"
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
	for i := 1; i <= n; i++ {
		fmt.Scan(&in_list[i])
	}

	increase := [LMIT]int{1}
	decrease := [LMIT]int{1}

	for i := 1; i <= n; i++ {
		increase[i] = 1
		decrease[i] = 1
	}

	for i := 1; i <= n; i++ {
		for j := 1; j < i; j++ {
			if in_list[i] > in_list[j] {
				increase[i] = max(increase[i], increase[j]+1)
			}
		}
	}

	for i := n; i >= 1; i-- {
		for j := n; j > i; j-- {
			if in_list[i] > in_list[j] {
				decrease[i] = max(decrease[i], decrease[j]+1)
			}
		}
	}

	max_val := 0
	for i := 1; i <= n; i++ {
		dp[i] = increase[i] + decrease[i] - 1
		if max_val < dp[i] {
			max_val = dp[i]
		}
	}
	fmt.Println(max_val)

}
