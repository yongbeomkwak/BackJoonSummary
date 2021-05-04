package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	var num int
	var input string
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscan(reader, &num, &input)

	var total int = 0

	for _, val := range input {
		total += int(val) - 48 // 0의 ascii code가 48이고
	}
	fmt.Println(total)
}
