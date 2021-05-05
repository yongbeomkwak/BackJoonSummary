package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var num string
	fmt.Fscanln(reader, &num)
	count := 0
	index := 0
	end := len(num) - 1
	for index <= end {
		curr := string(num[index])
		if curr == "c" {
			next_str := ""
			if index+1 <= end {
				next_str = string(num[index+1])
			} else {
				next_str = string(num[index])
			}
			if next_str == "=" || next_str == "-" {
				count += 1
				index += 2
				continue
			} else {
				count += 1
				index += 1
				continue
			}
		} else if curr == "d" {
			next_str := ""
			if index+1 <= end {
				next_str = string(num[index+1])
			} else {
				next_str = string(num[index])
			}
			if next_str == "-" {
				count += 1
				index += 2
				continue
			} else if next_str == "z" {
				nnext_str := ""
				if index+2 <= end {
					nnext_str = string(num[index+2])
				} else {
					nnext_str = string(num[index+1])
				}
				if nnext_str == "=" {
					count += 1
					index += 3
					continue
				} else {
					count += 1
					index += 1
					continue
				}
			} else {
				count += 1
				index += 1
				continue
			}
		} else if curr == "l" || curr == "n" {
			next_str := ""
			if index+1 <= end {
				next_str = string(num[index+1])
			} else {
				next_str = string(num[index])
			}
			if next_str == "j" {
				count += 1
				index += 2
				continue
			} else {
				count += 1
				index += 1
				continue
			}
		} else if curr == "s" || curr == "z" {
			next_str := ""
			if index+1 <= end {
				next_str = string(num[index+1])
			} else {
				next_str = string(num[index])
			}

			if next_str == "=" {
				count += 1
				index += 2
				continue
			} else {
				count += 1
				index += 1
			}
		} else {
			count += 1
			index += 1
		}

	}
	fmt.Println(count)
}
