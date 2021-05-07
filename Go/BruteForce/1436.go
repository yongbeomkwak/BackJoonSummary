package main

import (
	"fmt"
	"strconv"
	"strings"
)

func checkEndNumber(num string) bool {
	if strings.Contains(num, "666") {
		return true
	} else {
		return false
	}
}

func main() {
	//reader := bufio.NewReader(os.Stdin)
	num := 0
	fmt.Scan(&num)
	start := 665
	count := 0
	for count != num {
		start++
		if checkEndNumber(strconv.Itoa(start)) {
			count++
		}
	}
	fmt.Print(start)
}
