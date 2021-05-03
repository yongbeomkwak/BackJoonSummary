package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	var a, count int
	reader := bufio.NewReader(os.Stdin)
	var inputs [42]int // 기본값이 0 인 List

	for i := 0; i < 10; i++ {
		fmt.Fscan(reader, &a)
		if inputs[a%42] == 0 {
			inputs[a%42] = 1
		}
	}

	for _, val := range inputs {
		count += val
	}
	fmt.Print(count)
}
