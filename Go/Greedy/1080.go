package main

import (
	"bufio"
	"os"
	"strconv"
	"strings"
)

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
	wr := bufio.NewWriter(os.Stdout)
	A := make([]string, 0)
	B := make([]string, 0)
	C := [51][51]bool{{false}}
	defer wr.Flush()
	text, _ := r.ReadString('\n') // n 입력
	N_M := strings.Fields(text)
	N, _ := strconv.Atoi(N_M[0])
	M, _ := strconv.Atoi(N_M[1])
	for i := 0; i < N; i++ {
		input_A, _ := r.ReadString('\n')
		input_A = strings.TrimSuffix(input_A, "\n")
		A = append(A, input_A)
	}
	for i := 0; i < N; i++ {
		input_B, _ := r.ReadString('\n')
		input_B = strings.TrimSuffix(input_B, "\n")
		B = append(B, input_B)
		for j := 0; j < M; j++ {
			if A[i][j] == B[i][j] {
				C[i][j] = true
			}
		}
	}
	answer := 0
	if N < 3 || M < 3 {
		for i := 0; i < N; i++ {
			for j := 0; j < M; j++ {
				if !C[i][j] {
					answer = -1
					break
				}
			}
		}
		wr.WriteString(strconv.Itoa(answer))
	} else {
		for i := 0; i < N-2; i++ {
			for j := 0; j < M-2; j++ {
				if !C[i][j] {
					answer++
					for p := i; p < i+3; p++ {
						for q := j; q < j+3; q++ {
							C[p][q] = !C[p][q]
						}
					}
				}
			}
		}

		for i := 0; i < N; i++ {
			for j := 0; j < M; j++ {
				if !C[i][j] {
					answer = -1
					break
				}
			}
		}
		wr.WriteString(strconv.Itoa(answer))

	}

	// for i := 0; i < N; i++ {
	// 	text2, _ := r.ReadString('\n')   // n 입력
	// 	text2 = strings.TrimSpace(text2) //뒤에 \n제거
	// }

}
