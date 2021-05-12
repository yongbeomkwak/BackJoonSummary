package main

import (
	"fmt"
	"math"
)

var N int = 0
var MAX int = 20
var existTeam = make([]bool, MAX)
var Tgap int = 999999
var s = make([][]int, 0)

func DFS(nowPlayer int, playerCount int) {
	if playerCount == N/2 {
		star_team := make([]int, 0)
		link_team := make([]int, 0)

		for i := 0; i < N; i++ {
			if existTeam[i] {
				star_team = append(star_team, i)
			} else {
				link_team = append(link_team, i)
			}
		}

		star_teamPoint := 0
		link_teamPoint := 0

		for i := 0; i < len(star_team); i++ {
			for j := i + 1; j < len(star_team); j++ {
				star_i := star_team[i]
				star_j := star_team[j]
				link_i := link_team[i]
				link_j := link_team[j]
				star_teamPoint += s[star_i][star_j] + s[star_j][star_i]
				link_teamPoint += s[link_i][link_j] + s[link_j][link_i]
			}
		}
		now_PointGap := int(math.Abs(float64(star_teamPoint - link_teamPoint)))
		Tgap = int(math.Min(float64(Tgap), float64(now_PointGap)))
	} else {
		for i := nowPlayer + 1; i < N; i++ {
			if !existTeam[i] {
				existTeam[i] = true
				DFS(i, playerCount+1)
				existTeam[i] = false
			}
		}
	}
}

func main() {
	//reader := bufio.NewReader(os.Stdin)
	fmt.Scanln(&N)
	for i := 0; i < N; i++ {
		temp_slice := make([]int, 0)
		for j := 0; j < N; j++ {

			temp := 0
			fmt.Scan(&temp)
			temp_slice = append(temp_slice, temp)
		}
		s = append(s, temp_slice)
	}

	DFS(0, 0)
	fmt.Println(Tgap)

}
