package main

import (
	"fmt"
	"math"
)

const LMIT int = 301

var in_list = [LMIT]int{0}
var dp = [LMIT]int{0}

func main() {
	n := 0
	fmt.Scan(&n)

	for i := 0; i < n; i++ {
		fmt.Scan(&in_list[i])
	}

	dp[0] = in_list[0]
	dp[1] = in_list[0] + in_list[1]
	dp[2] = int(math.Max(float64(in_list[0]+in_list[2]), float64(in_list[1]+in_list[2])))

	for i := 3; i < n; i++ {
		dp[i] = int(math.Max(float64(dp[i-2]+in_list[i]), float64(dp[i-3]+in_list[i-1]+in_list[i])))
	}
	fmt.Println(dp[n-1])
}
