package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var a, b, c int
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscan(reader, &a, &b, &c)
	d := a * b * c
	var inputs = make([]int, 10)
	str := strings.Split(strconv.Itoa(d), "")

	for _, val := range str {
		temp, _ := strconv.Atoi(val)
		inputs[temp]++
	}

	for _, val := range inputs {
		fmt.Println(val)
	}
}
