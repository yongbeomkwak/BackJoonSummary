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

	for i := length; i >= 1; i-- {
		fmt.Fprintln(writer, i)
	}
	writer.Flush()
}
