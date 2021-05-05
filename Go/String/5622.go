package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var a string
	fmt.Fscanln(reader, &a)
	count := 0
	for _, val := range a {
		if val <= 79 {
			count += (int(val)-65)/3 + 3
		} else if val >= 80 && val <= 83 {
			count += 8
		} else if val >= 84 && val <= 86 {
			count += 9
		} else {
			count += 10
		}

	}
	fmt.Println(count)
}
