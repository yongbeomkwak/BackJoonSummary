package main

import (
	"fmt"
	"strings"
)

func main() {
	//reader := bufio.NewReader(os.Stdin)
	var M, N int
	fmt.Scanln(&M, &N)
	chase := make([][]string, 0)
	for i := 0; i < M; i++ {
		temp := ""
		fmt.Scan(&temp)
		temp_slice := strings.Split(temp, "")
		chase = append(chase, temp_slice)
	}
	W := make([]string, 0)
	B := make([]string, 0)
	for i := 0; i < 8; i++ {
		if i%2 == 0 {
			W = append(W, "W")
		} else {
			W = append(W, "B")
		}
	}
	for i := 0; i < 8; i++ {
		if i%2 == 0 {
			B = append(B, "B")
		} else {
			B = append(B, "W")
		}
	}
	min_value := 9999
	for p := 0; p < M-7; p++ {
		for q := 0; q < N-7; q++ {
			white_count := 0
			black_count := 0
			for i := p; i < p+8; i++ {
				for j := q; j < q+8; j++ {
					if i%2 == 0 {
						if chase[i][j] != W[j-q] {
							white_count++
						}
						if chase[i][j] != B[j-q] {
							black_count++
						}
					} else {
						if chase[i][j] != B[j-q] {
							white_count++
						}
						if chase[i][j] != W[j-q] {
							black_count++
						}
					}

				}
			}
			var temp int
			if white_count > black_count {
				temp = black_count
			} else {
				temp = white_count
			}
			if min_value > temp {
				min_value = temp
			}
		}
	}
	fmt.Println(min_value)
}
