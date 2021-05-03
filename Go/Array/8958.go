package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	var tc int
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscan(reader, &tc)

	for i := 0; i < tc; i++ {
		prev_score := 0
		total := 0
		var input string
		fmt.Fscan(reader, &input)
		a := strings.Split(input, "")
		for _, val := range a {
			if val == "O" {
				prev_score++
				total += prev_score
			} else {
				prev_score = 0
			}
		}
		fmt.Println(total)
	}

}
