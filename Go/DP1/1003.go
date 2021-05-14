package main

import "fmt"

func main() {
	//reader := bufio.NewReader(os.Stdin)
	var tc int = 0
	fmt.Scan(&tc)
	for i := 0; i < tc; i++ {
		n := 0
		fmt.Scan(&n)
		zero := 1
		one := 0
		tmp := 0
		for j := 0; j < n; j++ {
			tmp = one
			one = one + zero
			zero = tmp
		}
		fmt.Println(zero, one)
	}
}
