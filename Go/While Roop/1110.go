package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	var a int
	b := 0
	// use bufio for fast scan
	reader := bufio.NewReader(os.Stdin)
	_, err := fmt.Fscanln(reader, &a)
	final := a
	for {
		if err == nil { //에러가 없으면
			b++
			c := final / 10   //십의 자리
			d := final % 10   //일의자리 ,다음 수의 십의자리
			e := (c + d) % 10 // 다음 수의 일의자리
			final = (d * 10) + e
			if final == a {
				fmt.Print(b)
				break
			} else {
				continue
			}

		} else {
			break
		}

	}

}
