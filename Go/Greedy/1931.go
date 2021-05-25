package main

import (
	"fmt"
	"sort"
)

type Time struct {
	start int
	end   int
}

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	N := 0
	fmt.Scan(&N)
	grd := make([]Time, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&grd[i].start, &grd[i].end)
	}
	sort.Slice(grd, func(i, j int) bool {
		if grd[i].end == grd[j].end {
			return grd[i].start < grd[j].start
		} else {
			return grd[i].end < grd[j].end
		}
	})
	cnt := 1
	endTime := grd[0].end
	for i := 1; i < N; i++ {
		if endTime <= grd[i].start {
			endTime = grd[i].end
			cnt++
		}
	}
	fmt.Println(cnt)

}
