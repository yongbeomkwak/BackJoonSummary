package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	var input string
	reader := bufio.NewReader(os.Stdin)
	//bufio의 NewReader로 standard input을 받는 입력 인스턴스 kbReader를 생성합니다.
	input, _ = reader.ReadString('\n') //ReadString('\n')에서는 엔터키를 받을 때까지 키보드의 입력을 받습니다.
	//한줄 입력 받기 , 뜨어쓰기 포함

	words := strings.Split(input, " ") //해당 문자열을 " "을 기준으로 잘라 배열 형태로 저장
	var count int
	for i := range words {
		if words[i] != "\n" && words[i] != "" { //비어있거나 엔터 입력아니면 문자로 취급하여 단어 저장
			count++
		}
	}
	fmt.Println(count)
}
