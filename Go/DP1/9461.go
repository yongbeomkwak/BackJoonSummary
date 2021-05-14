package main

import "fmt"

const LMIT int = 101

func main() {

	dp := make([]int, LMIT)
	dp[1] = 1
	dp[2] = 1
	dp[3] = 1
	tc := 0
	fmt.Scan(&tc)

	for i := 0; i < tc; i++ {
		n := 0
		fmt.Scan(&n)
		for i := 4; i <= n; i++ {
			dp[i] = dp[i-3] + dp[i-2]
		}
		fmt.Println(dp[n])
	}
}
