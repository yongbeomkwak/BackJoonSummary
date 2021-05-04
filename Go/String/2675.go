package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	var input string
	var roop int
	var tc int
	reader := bufio.NewReader(os.Stdin)
	fmt.Scanf("%d", &tc)

	for i := 0; i < tc; i++ {
		fmt.Fscanln(reader, &roop, &input)
		for _, val := range input {
			for i := 0; i < roop; i++ {
				fmt.Print(string(val)) //(rune to string)
			}
		}
		fmt.Println()
	}

}
