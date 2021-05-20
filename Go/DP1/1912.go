package main

import "fmt"

const LMIT = 100000

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
	for i := 0; i < n; i++ {
		fmt.Scan(&in_list[i])
	}
	dp[0] = in_list[0]
	result := in_list[0]
	for i := 1; i < n; i++ {
		dp[i] = max(dp[i-1]+in_list[i], in_list[i])
		result = max(result, dp[i])
	}
	fmt.Println(result)
}
