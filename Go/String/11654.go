package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	var input byte
	reader := bufio.NewReader(os.Stdin)
	input, _ = reader.ReadByte()
	fmt.Printf("%d\n", input)
}
