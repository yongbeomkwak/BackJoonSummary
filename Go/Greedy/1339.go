package main

import (
	"bufio"
	"math"
	"os"
	"sort"
	"strconv"
	"strings"
)

func max(a int, b int) bool {
	if a > b {
		return true
	}
	return false
}

func main() {
	/*
			Scan과 Reader는 같이 사용 못함 알 수 없는 버그 발생 가능

			bufio.Scanner는 bufio.Reader를 대신하여 줄 바꿈 등으로 구분되는 텍스트 파일 등의 데이터를 읽는 편리한 인터페이스를 제공합니다.
			bufio.Reader와 눈에 띄는 가장 큰 차이점이라면, 입력을 받았을 때, 읽어 들인 값이 \n 을 포함하지 않는다는 점입니다.
			이 덕분에 strings.TrimSuffix(_, "\n") 등의 작업을 추가로 해줄 필요가 없습니다.

			ext, _ := reader.ReadString('\n') ;
			text = strings.TrimSpace(text) 와 같이 한 줄을 읽어들이거나,
			scanner.Split(bufio.ScanWords) ;
			scanner.Scan() ; text := scanner.Text()
			와 같이 토큰을 하나 가져와서 a, _ := strconv.Atoi(text) 와 같이 직접 파싱하면 충분히 빠릅니다.

		개인적으로 전자(Reader)는 한 줄에 배열의 정보가 전부 들어올 때 strings.Fields()를 같이 활용해서 입력받을 때 편하고,

		후자(scanner)는 데이터를 한 단어 한 단어 가져올 때 편합니다.
		다만 당연히 둘 다 같이 쓸 수는 없으니 혼용이 필요할 땐 적절히 타협을 봐야 합니다.

	*/
	// sc := bufio.NewScanner(os.Stdin)
	// sc.Scan()
	// text := sc.Text()

	/*
		-------- Reader --------
	*/
	r := bufio.NewReader(os.Stdin)
	text, _ := r.ReadString('\n')  // n 입력
	text = strings.TrimSpace(text) //뒤에 \n제거
	N, _ := strconv.Atoi(text)     //형 변환
	wr := bufio.NewWriter(os.Stdout)
	result := 0
	alpha := make([]int, 26)
	input := make([]string, 0)
	for i := 0; i < N; i++ {
		temp, _ := r.ReadString('\n')
		temp = strings.TrimSpace(temp) //뒤에 \n제거
		input = append(input, temp)
	}
	for _, s := range input {
		size := int(math.Pow(10, float64(len(s)-1)))

		for _, c := range s { // c는 바로 rune(ascii) 형태
			alpha[c-65] += size
			size /= 10
		}
	}
	sort.Sort(sort.Reverse(sort.IntSlice(alpha))) //내림차순
	_const := 9
	for i := 0; i < 26; i++ {
		if alpha[i] == 0 {
			break
		}
		result += _const * alpha[i]
		_const--

	}
	wr.WriteString(strconv.Itoa(result))
	defer wr.Flush()
}
