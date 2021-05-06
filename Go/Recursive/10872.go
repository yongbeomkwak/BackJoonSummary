package main

import (
	"bufio"
	"fmt"
	"os"
)

func fact(a int) int {
	if a < 1 {
		return 1
	} else {
		return a * fact(a-1)
	}
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	a := 0
	fmt.Fscan(reader, &a)
	fmt.Println(fact(a))
}
