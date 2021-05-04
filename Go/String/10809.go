package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	var list []int
	for i := 0; i < 26; i++ {
		list = append(list, -1)
	}
	var input string
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscan(reader, &input)

	for index, val := range input {
		if list[int(val)-97] == -1 {
			list[int(val)-97] = index
		}
	}

	for _, val := range list {
		fmt.Printf("%d ", val)
	}

}
