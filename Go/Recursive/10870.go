package main

import (
	"bufio"
	"fmt"
	"os"
)

func fibo(a int) int {
	if a == 0 {
		return 0
	} else if a < 2 {
		return 1
	} else {
		return fibo(a-1) + fibo(a-2)
	}
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	a := 0
	fmt.Fscan(reader, &a)
	fmt.Println(fibo(a))
}
