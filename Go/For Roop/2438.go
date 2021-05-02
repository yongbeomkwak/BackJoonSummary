package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	var length int

	// use bufio for fast scan
	reader := bufio.NewReader(os.Stdin)
	//writer := bufio.NewWriter(os.Stdout)
	fmt.Fscanln(reader, &length)

	for i := 1; i <= length; i++ {
		for j := 1; j <= i; j++ {
			fmt.Print("*")
		}
		fmt.Println()
	}

}
