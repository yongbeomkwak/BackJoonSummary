package main

import "fmt"

const LMIT = 1000001

var dp [LMIT]int

func main() {
	n := 0
	fmt.Scan(&n)

	for i := 2; i <= n; i++ {
		dp[i] = dp[i-1] + 1

		if i%2 == 0 && dp[i] > (dp[i/2]+1) {
			dp[i] = dp[i/2] + 1
		}
		if i%3 == 0 && dp[i] > (dp[i/3]+1) {
			dp[i] = dp[i/3] + 1
		}
	}
	fmt.Println(dp[n])

}
