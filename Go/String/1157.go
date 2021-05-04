package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var input string
	fmt.Fscan(reader, &input)
	m := make(map[string]int) //Map 생성

	for i := 65; i < 91; i++ { //A(65) -> Z(90)
		m[string(i)] = 0 // Ascii code를 string으로, 해당 키와 value로 맵 요소 삽입
	}

	for _, val := range input {
		//입력 받은 문자열(ASCII)을 string으로 바꾼후 대문자로 변경 한 후
		//해당 키를 가진 value를 증가
		m[strings.ToUpper(string(val))]++
	}
	var max_value int = 0
	var max_key string
	check := 0
	for _, val := range m {
		if val > max_value {
			max_value = val
		}
	}

	for key, val := range m {
		if max_value == val {
			check++
			max_key = key
		}
	}

	if check > 1 {
		fmt.Print("?")
	} else {
		fmt.Print(max_key)
	}

}
