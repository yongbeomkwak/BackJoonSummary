package main

import "fmt"

const LMIT int = 1000001

func main() {

	dp := make([]int, LMIT)
	dp[1] = 1
	dp[2] = 2
	n := 0
	fmt.Scan(&n)

	for i := 3; i <= n; i++ {
		dp[i] = (dp[i-1] + dp[i-2]) % 15746
	}
	fmt.Println(dp[n])
}
