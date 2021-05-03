package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	var n int
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscanln(reader, &n)

	var inputs = make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &inputs[i])
	}

	sort.Slice(inputs, func(i, j int) bool {
		return inputs[i] < inputs[j]
	})

	fmt.Printf("%d %d\n", inputs[0], inputs[len(inputs)-1])
}
