package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

const LMIT int = 501

var in_list = make([][]int, LMIT)
var dp = [LMIT][LMIT]int{{0}}

func main() {
	reader := bufio.NewReader(os.Stdin)
	n := 0
	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		str, _ := reader.ReadString('\n')
		str_list := strings.Fields(str) //공백으로 나눈 후 []string
		tmp_list := make([]int, 0)
		for _, val := range str_list {
			tmp, _ := strconv.Atoi((val))
			tmp_list = append(tmp_list, tmp) //1차원 배열에 int로 바꿔 ㄴ허기
		}
		in_list[i] = append(in_list[i], tmp_list...)
	}
	dp[0][0] = in_list[0][0]
	for i := 1; i < n; i++ {
		for j := 0; j <= i; j++ {
			if j == 0 {
				dp[i][j] = dp[i-1][j] + in_list[i][j]
			} else if j == i {
				dp[i][j] = dp[i-1][j-1] + in_list[i][j]
			} else {
				dp[i][j] = int(math.Max(float64(dp[i-1][j-1]), float64(dp[i-1][j]))) + in_list[i][j]
			}

		}
	}
	ans := -1
	for i := 0; i < n; i++ {
		if ans < dp[n-1][i] {
			ans = dp[n-1][i]
		}
	}
	fmt.Println(ans)

}
