package main

import (
	"bufio"
	"fmt"
	"os"
)

func cal(a int) int {
	c := 0
	if a > 1 {
		for i := 1; i <= a; i++ {
			if ((3 * i * i) + (-3 * i) + 1) >= a {
				c = i
				return c
			}
		}
	}
	return 1
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	a := 0
	fmt.Fscan(reader, &a)
	fmt.Println(cal(a))
}
