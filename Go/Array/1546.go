package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	var sub int
	reader := bufio.NewReader(os.Stdin)
	var slice_score []float32
	fmt.Fscan(reader, &sub)
	for i := 0; i < sub; i++ {
		var temp float32
		fmt.Fscan(reader, &temp)
		slice_score = append(slice_score, temp)
	}

	sort.Slice(slice_score, func(i, j int) bool {
		return slice_score[i] < slice_score[j]
	})
	max := slice_score[sub-1]
	var avg float32
	for _, val := range slice_score {

		avg += float32(val/max) * 100
	}
	fmt.Print(avg / float32(sub))

}
