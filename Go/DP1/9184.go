package main

import (
	"bufio"
	"fmt"
	"os"
)

const LMIT int = 21

var dp [LMIT][LMIT][LMIT]int

func w(a int, b int, c int) int {
	if a <= 0 || b <= 0 || c <= 0 {
		return 1
	}
	if a > 20 || b > 20 || c > 20 {
		return w(20, 20, 20)
	}

	if dp[a][b][c] != 0 {
		return dp[a][b][c]
	}

	if a < b && b < c {
		dp[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c)
		return dp[a][b][c]
	}
	dp[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)
	return dp[a][b][c]
}

func main() {

	for true {
		writer := bufio.NewWriter(os.Stdout)
		a := 0
		b := 0
		c := 0
		fmt.Scan(&a, &b, &c)
		if a == -1 && b == -1 && c == -1 {
			break
		}
		fmt.Fprintf(writer, "w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c))
		writer.Flush()
	}
}
