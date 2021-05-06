package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var result int = 0
var M int = 0
var N int = 0

func blackJack(fin int, list []int, sum int, now int) {
	if fin == 3 {
		if M-sum <= M-result && M-sum >= 0 {
			result = sum
		}
		return
	} else {
		for i := now; i < N; i++ {
			blackJack(fin+1, list, sum+list[i], i+1)
		}
	}
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscanln(reader, &N, &M)
	list := make([]int, 0)
	input, _ := reader.ReadString('\n') //한줄 입력
	input_list := strings.Fields(input) //띄어쓰기로 구분
	for _, val := range input_list {
		temp, _ := strconv.Atoi(val)
		list = append(list, temp)
	}
	blackJack(0, list, 0, 0)
	fmt.Println(result)

}
