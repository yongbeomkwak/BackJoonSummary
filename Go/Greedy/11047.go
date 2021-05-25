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
	m := make([]int, 0)
	cnt := 0
	for i := 0; i < N; i++ {
		temp := 0
		fmt.Scan(&temp)
		m = append(m, temp)
	}
	for i := N - 1; i >= 0; i-- {
		if K == 0 {
			break
		}
		if m[i] > K {
			continue
		}
		cnt += K / m[i]
		K %= m[i]
	}
	fmt.Println(cnt)
}
