package main

import "fmt"

const LMIT = 1001

var dp [LMIT][LMIT]int

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	a := ""
	b := ""
	fmt.Scan(&a, &b)

	for i := 1; i <= len(a); i++ {
		for j := 1; j <= len(b); j++ {
			if a[i-1] == b[j-1] {
				dp[i][j] = dp[i-1][j-1] + 1
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1])
			}
		}
	}
	fmt.Print(dp[len(a)][len(b)])

}
