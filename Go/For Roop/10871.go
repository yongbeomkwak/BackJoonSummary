package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	var length int
	var x int
	// use bufio for fast scan
	reader := bufio.NewReader(os.Stdin)
	//writer := bufio.NewWriter(os.Stdout)
	var temp_slice []int //Slice ,길이가 정해지지 않은 List
	var temp int
	fmt.Fscanln(reader, &length, &x)
	for i := 0; i < length; i++ {
		fmt.Fscan(reader, &temp)
		if temp < x {
			temp_slice = append(temp_slice, temp) //append는 리턴값이 해당 값을 추가한 slice를 리턴
		}
	}

	for _, val := range temp_slice {
		fmt.Printf("%d ", val)
	}
}
