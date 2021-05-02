package main

import (
	"fmt"
)

func main() {
	var h, m int
	fmt.Scanf("%d %d", &h, &m)
	var mm int
	mm = m - 45
	if mm >= 0 {
		fmt.Print(h, mm)
	} else {
		var new_m int = 60 + mm
		var new_h = h - 1
		if new_h >= 0 {
			fmt.Print(new_h, new_m)
		} else {
			fmt.Print(23, new_m)
		}
	}

}
