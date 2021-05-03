package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	var n int = 9
	reader := bufio.NewReader(os.Stdin)

	var inputs = make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &inputs[i])
	}
	temp := make([]int, len(inputs))
	copy(temp, inputs) //얕은 복사

	sort.Slice(inputs, func(i, j int) bool {
		return inputs[i] < inputs[j]
	})

	for index, val := range temp {
		if val == inputs[8] {

			fmt.Println(val)
			fmt.Print(index + 1)
			break
		}
	}

}
