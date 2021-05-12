package main

import (
	"fmt"
)

var N int = 0
var M int = 0
var arr = make([]int, 10)
var used = make([]int, 10)

func back(curr int) {
	if curr == M {
		for i := 0; i < M; i++ {
			fmt.Printf("%d ", arr[i])
		}
		fmt.Println()
		return
	} else {
		for i := 1; i <= N; i++ {
			if used[i] == 0 {
				used[i] = 1
				arr[curr] = i
				back(curr + 1)
				used[i] = 0
			}
		}
	}

}

func main() {
	//reader := bufio.NewReader(os.Stdin)
	fmt.Scanln(&N, &M)
	back(0)

}
