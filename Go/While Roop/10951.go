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
		_, err := fmt.Fscanln(reader, &a, &b)
		if err == nil { //에러가 없으면
			fmt.Println(a + b)
		} else {
			break
		}

	}

}
