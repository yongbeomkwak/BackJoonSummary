package main

import (
	"fmt"
)

func main() {
	var x int
	fmt.Scanf("%d", &x)

	for i := 1; i <= 9; i++ {
		fmt.Printf("%d * %d = %d\n", x, i, x*i)
	}

}
