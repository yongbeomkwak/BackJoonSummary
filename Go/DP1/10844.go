package main

import "fmt"

const LMIT = 101
const MOD = 1000000000

var dp [LMIT][11]int

func main() {
	n := 0
	fmt.Scan(&n)

	for i := 1; i <= 9; i++ {
		dp[1][i] = 1
	}

	for i := 2; i <= n; i++ {
		for j := 0; j <= 9; j++ {
			if j == 0 {
				dp[i][0] = dp[i-1][1]
			} else {
				dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % MOD
			}
		}
	}
	sum := 0
	for i := 0; i <= 9; i++ {
		sum += dp[n][i]
	}
	fmt.Println(sum % MOD)
}
