package main

import (
	"fmt"
	"strconv"
)

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	str := ""
	tmp := ""
	plus := true
	result := 0
	fmt.Scan(&str)

	for i := 0; i <= len(str); i++ {
		if i == len(str) {
			if plus {
				temp, _ := strconv.Atoi(tmp)
				result += temp
			} else {
				temp, _ := strconv.Atoi(tmp)
				result -= temp
			}
			break
		}
		if string(str[i]) == "+" || string(str[i]) == "-" || string(str[i]) == "\n" {
			if plus {
				temp, _ := strconv.Atoi(tmp)
				result += temp
			} else {
				temp, _ := strconv.Atoi(tmp)
				result -= temp
			}
			if string(str[i]) == "-" {
				plus = false
			}
			tmp = ""
			continue
		}
		tmp += string(str[i])
	}
	fmt.Println(result)
}
