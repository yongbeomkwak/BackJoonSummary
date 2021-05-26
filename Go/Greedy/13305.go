package main

import (
	"fmt"
)

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	const LMIT = 100001
	const MAX = 1000000000
	var dis [LMIT]int
	var grd [LMIT]int
	mincost := MAX
	N := 0
	result := 0
	mindex := 0
	L := 0
	fmt.Scan(&N)
	for i := 1; i < N; i++ { //거리 입력 받기
		fmt.Scan(&dis[i])
		L += dis[i]
	}
	for i := 1; i < N; i++ { //cost 입력 받기
		fmt.Scan(&grd[i])
		if grd[i] < mincost { //가장 적은 비용및 해당 도시 인덱스 얻음
			mincost = grd[i]
			mindex = i
		}
	}
	if mindex == 1 { //만약 해당 인덱스가 1이면 출발지점에서 모두 넣으면됨
		result = grd[1] * L
	} else { //아닐 경우
		mincost = grd[1]
		result += mincost * dis[1]
		L -= dis[1]
		// 출발지에서 다음 도시로 건넌 후
		for i := 2; i < mindex; i++ { // 최소 도시까지 반복문 돌림
			if mincost < grd[i] { //만약 과거의 비용이 더 싸면 과거 비용으로 결제
				result += mincost * dis[i]
				L -= dis[i]
			} else { //아니면 비용 업데이트 후 결제
				mincost = grd[i]
				result += mincost * dis[i]
				L -= dis[i]
			}
		}
		result += grd[mindex] * L //마지막으로 최소 도시에서 나머지 거리 결제
	}
	fmt.Print(result) //출력

}
