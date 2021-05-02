package main

import (
	"fmt"
)

func main() {
	var x int
	fmt.Scanf("%d", &x)

	for i := 0; i < x; i++ {
		var a, b int
		fmt.Scanf("%d %d", &a, &b)
		fmt.Println(a + b)
	}

}
