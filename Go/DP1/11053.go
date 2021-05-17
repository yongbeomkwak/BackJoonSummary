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

	for i := 1; i <= n; i++ {
		dp[i] = 1
	}

	ans := 1
	for i := 1; i <= n; i++ {
		for j := 0; j <= i; j++ {
			if in_list[i] > in_list[j] {
				dp[i] = max(dp[i], dp[j]+1)
			}
		}
		ans = max(ans, dp[i])
	}

	fmt.Println(ans)
}
