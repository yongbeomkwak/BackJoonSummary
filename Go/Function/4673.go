package main

import (
	"bufio"
	"fmt"
	"os"
)

func solve(a int) bool {
	for i := a; i > 0; i-- {
		result := 0
		if i < 10 {
			result = i + i
			if result < a {
				return false
			} else if result == a {
				return true
			}
		} else if i >= 10 && i < 100 {
			result = i + (i / 10) + (i % 10)
			if result == a {
				return true
			}
		} else if i >= 100 && i < 1000 {
			result = i + (i / 100) + ((i % 100) / 10) + (i % 10)
			if result == a {
				return true
			}
		} else if i >= 1000 && i < 10000 {
			result = i + (i / 1000) + ((i % 1000) / 100) + ((i % 100) / 10) + (i % 10)
			if result == a {
				return true
			}
		}
	}
	return false
}

func main() {

	writer := bufio.NewWriter(os.Stdout)
	for i := 1; i < 10001; i++ {
		if solve(i) {
			continue
		} else {
			fmt.Fprintln(writer, i)
		}
	}

	defer writer.Flush()

}
