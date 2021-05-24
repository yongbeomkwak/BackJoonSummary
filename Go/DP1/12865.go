package main

import "fmt"

const LMIT = 100001

var dp [102][LMIT]int
var in_list [102][2]int

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	N := 0
	K := 0
	fmt.Scan(&N, &K)

	for i := 1; i <= N; i++ {
		fmt.Scan(&in_list[i][0], &in_list[i][1])
	}

	for i := 1; i <= N; i++ {
		W := in_list[i][0]
		val := in_list[i][1]
		for j := 0; j <= K; j++ {
			if j < W {
				dp[i][j] = dp[i-1][j]
			} else {
				dp[i][j] = max(dp[i-1][j-W]+val, dp[i-1][j])
			}
		}
	}
	fmt.Print(dp[N][K])
}
