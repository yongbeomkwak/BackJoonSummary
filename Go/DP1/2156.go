package main

import "fmt"

const LMIT = 10001

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
	dp[1] = in_list[1]
	if n > 1 {
		//1보다 클 때만 인덱스 2 접근 할 수 있으므로
		dp[2] = dp[1] + in_list[2]
	}

	for i := 3; i <= n; i++ {
		//dp[i]=현재 까지 먹은 와인 점수
		//경우1: 연속 1번 먹기(두번째 전(i-2)+i(현재))
		//경우2: 연속 2번 먹기(3번째전(i-3)+(i-1)+i))
		//경우3: 연속 0번 먹기 max(dp[i],dp[i-1]) 안 먹으니 그 전 결과 그대로 가져오기
		dp[i] = max(dp[i-2]+in_list[i], dp[i-3]+in_list[i-1]+in_list[i])
		dp[i] = max(dp[i], dp[i-1])
	}
	fmt.Println(dp[n])

}
