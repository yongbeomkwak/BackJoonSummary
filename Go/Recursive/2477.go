package main

import (
	"bufio"
	"fmt"
	"os"
)

func solve(x int, y int, n int, star [][]string) { //star 2차원 slice

	if n == 3 {
		for i := 0; i < 3; i++ {
			for j := 0; j < 3; j++ {
				if i == 1 && j == 1 {
					star[x+i][y+j] = " " //가운데 빈칸
					continue
				}
				star[x+i][y+j] = "*"
			}
		}
		return //재귀 종료
	}
	m := n / 3
	for i := 0; i < 3; i++ {
		for j := 0; j < 3; j++ {
			if i == 1 && j == 1 {
				continue
			}
			solve(x+i*m, y+j*m, m, star)
		}
	}
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	num := 0
	fmt.Fscan(reader, &num)
	list := make([][]string, num) //2차원 슬라이스 만들기

	for i := 0; i < num; i++ {
		for j := 0; j < num; j++ {
			list[i] = append(list[i], " ")
		}
	}
	solve(0, 0, num, list)

	for i := 0; i < num; i++ {
		for j := 0; j < num; j++ {
			fmt.Print(list[i][j])
		}
		fmt.Println()
	}
}
