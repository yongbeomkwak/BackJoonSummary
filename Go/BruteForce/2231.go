package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var result int = 1000001

func partailSum(n int) {

	for i := n; i > 0; i-- {
		str_n := strconv.Itoa(i)
		curr := i
		for _, j := range str_n {
			int_j, _ := strconv.Atoi(string(j))

			curr += int_j

		}
		if curr == n && result >= i {
			result = i
		}
	}

}

func main() {
	reader := bufio.NewReader(os.Stdin)
	var N int
	fmt.Fscanln(reader, &N)
	partailSum(N)

	if result != 1000001 {
		fmt.Println(result)
	} else {
		fmt.Println(0)
	}

}
