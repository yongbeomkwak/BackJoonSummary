package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var A, B, C int
	fmt.Fscanln(reader, &A, &B, &C)

	if B >= C {
		fmt.Print(-1)
	} else {
		fmt.Print(A/(C-B) + 1)
	}
}
