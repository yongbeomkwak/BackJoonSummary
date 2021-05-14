package main

import (
	"fmt"
	"math"
)

var in_list = make([][]int, 0)
var dp = [1001][3]int{{0, 0, 0}}

func main() {
	n := 0
	fmt.Scan(&n)

	for i := 0; i < n; i++ {
		var r, g, b int
		tmp := make([]int, 0)
		fmt.Scan(&r, &g, &b)
		tmp = append(tmp, r)
		tmp = append(tmp, g)
		tmp = append(tmp, b)
		in_list = append(in_list, tmp)
	}

	dp[0][0] = in_list[0][0]
	dp[0][1] = in_list[0][1]
	dp[0][2] = in_list[0][2]

	for i := 1; i < n; i++ {
		dp[i][0] = int(math.Min(float64(dp[i-1][1]), float64(dp[i-1][2]))) + in_list[i][0]
		dp[i][1] = int(math.Min(float64(dp[i-1][0]), float64(dp[i-1][2]))) + in_list[i][1]
		dp[i][2] = int(math.Min(float64(dp[i-1][0]), float64(dp[i-1][1]))) + in_list[i][2]
	}
	min := 99999999
	for i := 0; i < 3; i++ {
		if min > dp[n-1][i] {
			min = dp[n-1][i]
		}
	}
	fmt.Println(min)

}
