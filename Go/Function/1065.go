package main

import (
	"bufio"
	"fmt"
	"os"
)

func solve(a int) int {
	if a <= 99 {
		return a
	} else {
		count := 99
		for i := a; i > 99; i-- {
			th := i / 1000
			h := (i % 1000) / 100
			t := (i % 100) / 10
			o := (i % 10)
			if th == 0 {
				if (h - t) == (t - o) {
					count++
				} else {
					continue
				}
			}
		}
		return count
	}
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	var input int
	fmt.Fscan(reader, &input)
	writer := bufio.NewWriter(os.Stdout)
	fmt.Fprint(writer, solve(input))

	defer writer.Flush()

}
