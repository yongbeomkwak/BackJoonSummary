package main

import (
	"fmt"
)

func main() {
	var score int
	var grade string
	fmt.Scanf("%d", &score)
	//If 와 else if 와 else 모두 {} 이전 블락켓 끝나고 현재 블락켓이 여는 곳이 한 줄에 있어여함
	if score >= 90 && score <= 100 {
		grade = "A"
	} else if score >= 80 && score <= 89 {
		grade = "B"
	} else if score >= 70 && score <= 79 {
		grade = "C"
	} else if score >= 60 && score <= 69 {
		grade = "D"
	} else {
		grade = "F"
	}
	fmt.Println(grade)

}
