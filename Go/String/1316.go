package main

import (
	"fmt"
)

func main() {
	//reader := bufio.NewReader(os.Stdin)
	var tc int
	count := 0
	fmt.Scan(&tc)
	for i := 0; i < tc; i++ {
		var input string
		fmt.Scan(&input)
		end := len(input) - 1
		last_check := true
		for i := 0; i <= end; i++ {
			check := true
			second_check := false

			for j := end; j >= i; j-- {
				if (string(input[i]) == string(input[j])) && check && !second_check { //처음 같은 값 만날 때
					check = false //플래그 꺼짐
				} else if (string(input[i]) != string(input[j])) && !check && !second_check {
					second_check = true //같은 값이 아닌 값 감지 즉 이 다음 부터 같은 값 만나면 그룹단어 아님
				} else if (string(input[i]) == string(input[j])) && !check && second_check {
					last_check = false // 최종 그룹단어 탈락
					break
				}
			}
			if !last_check {
				break
			}
		}
		if last_check {
			count += 1
		}
	}
	fmt.Print(count)
}
