package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

func move(start int, dest int) {
	writer := bufio.NewWriter(os.Stdout)
	fmt.Fprintln(writer, start, dest)
	defer writer.Flush()
}

func hanoi(N int, start int, via int, dest int) {
	if N == 1 {
		move(start, dest)
		return
	} else {
		hanoi(N-1, start, dest, via)
		move(start, dest)
		hanoi(N-1, via, start, dest)
	}

}

func main() {
	reader := bufio.NewReader(os.Stdin)
	num := 0
	fmt.Fscan(reader, &num)
	fmt.Println(int(math.Pow(2.0, float64(num)) - 1))
	hanoi(num, 1, 2, 3)

}
