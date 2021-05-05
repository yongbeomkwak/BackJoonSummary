package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var a string
	var b string
	fmt.Fscanln(reader, &a, &b)

	var c int = 0
	var d int = 0

	for i := 2; i >= 0; i-- {
		temp1, _ := strconv.Atoi(string(b[i]))
		temp2, _ := strconv.Atoi(string(a[i]))
		temp1 *= int(math.Pow(10.0, float64(i)))
		temp2 *= int(math.Pow(10.0, float64(i)))
		c += temp1
		d += temp2
	}
	//golang은 삼항 연사자 없음
	if c > d {
		fmt.Println(c)
	} else {
		fmt.Println(d)
	}

}
