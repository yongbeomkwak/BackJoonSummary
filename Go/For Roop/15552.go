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
	writer := bufio.NewWriter(os.Stdout)
	fmt.Fscanln(reader, &length)

	var a, b int

	for i := 0; i < length; i++ {
		fmt.Fscanln(reader, &a, &b)
		fmt.Fprintln(writer, a+b)
	}
	writer.Flush()
}
