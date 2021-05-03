package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	var a, b int
	// use bufio for fast scan
	reader := bufio.NewReader(os.Stdin)

	for {
		fmt.Fscanln(reader, &a, &b)
		if a == 0 && b == 0 {
			break
		}
		fmt.Println(a + b)
	}

}
