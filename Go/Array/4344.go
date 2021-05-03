package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var tc int
	reader := bufio.NewReader(os.Stdin)
	fmt.Scan(&tc)

	for i := 0; i < tc; i++ {

		str, _ := reader.ReadString('\n')
		list := strings.Fields(str)
		stu_num, _ := strconv.Atoi(list[0])
		_list := list[1:]
		avg := 0
		for _, val := range _list {
			temp, _ := strconv.Atoi(val)
			avg += temp
		}
		avg /= stu_num
		count := 0
		for _, val := range _list {
			temp, _ := strconv.Atoi(val)
			if temp > avg {
				count++
			}
		}
		result := float32(count) / float32(stu_num) * 100
		fmt.Printf("%.3f%s\n", result, "%")

	}

}
