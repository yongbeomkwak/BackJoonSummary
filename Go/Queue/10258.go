package main

import (
	"bufio"
	"os"
	"strconv"
	"strings"
)

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

type Node struct {
	data int
	next *Node
}

type Queue struct {
	_front *Node
	_back  *Node
	_size  int
}

func createQueue() *Queue { //struct 생성 메소드
	queue := Queue{}
	queue._size = 0
	queue._back = nil
	queue._front = nil
	return &queue
}
func (qu *Queue) push(newInt int) { //포인터로 접근
	newNode := Node{}
	newNode.data = newInt
	newNode.next = nil
	if qu.size() == 0 {
		qu._front = &newNode
		qu._back = &newNode
	} else {
		qu._back.next = &newNode
		qu._back = &newNode
	}
	qu._size++
}

func (qu *Queue) pop() int {
	if qu._size == 0 {
		return -1
	}
	data := qu._front.data
	qu._front = qu._front.next
	qu._size--
	return data
}

func (qu *Queue) empty() int {
	if qu._size == 0 {
		return 1
	} else {
		return 0
	}
}
func (qu *Queue) size() int {
	return qu._size
}

func (qu *Queue) front() int {
	if qu._size == 0 {
		return -1
	} else {
		return qu._front.data
	}
}

func (qu *Queue) back() int {
	if qu._size == 0 {
		return -1
	} else {
		return qu._back.data
	}
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

		개인적으로 전자는 한 줄에 배열의 정보가 전부 들어올 때 strings.Fields()를 같이 활용해서 입력받을 때 편하고,

		후자는 데이터를 한 단어 한 단어 가져올 때 편합니다.
		다만 당연히 둘 다 같이 쓸 수는 없으니 혼용이 필요할 땐 적절히 타협을 봐야 합니다.

	*/
	// sc := bufio.NewScanner(os.Stdin)
	// sc.Scan()
	// text := sc.Text()

	/*
		-------- Reader --------
	*/
	queue := createQueue()
	r := bufio.NewReader(os.Stdin)
	text, _ := r.ReadString('\n')  // n 입력
	text = strings.TrimSpace(text) //뒤에 \n제거
	n, _ := strconv.Atoi(text)     //형 변환

	wr := bufio.NewWriter(os.Stdout)
	for i := 0; i < n; i++ {
		command, _ := r.ReadString('\n')
		command = strings.TrimSpace(command)
		x := strings.Fields(command) //배열로 만들기
		if len(x) > 1 {
			tmp, _ := strconv.Atoi(x[1])
			queue.push(tmp)
		} else {
			if x[0] == "pop" {
				wr.WriteString(strconv.Itoa(queue.pop()) + "\n")
			} else if x[0] == "front" {
				wr.WriteString(strconv.Itoa(queue.front()) + "\n")
			} else if x[0] == "back" {
				wr.WriteString(strconv.Itoa(queue.back()) + "\n")
			} else if x[0] == "empty" {
				wr.WriteString(strconv.Itoa(queue.empty()) + "\n")
			} else {
				wr.WriteString(strconv.Itoa(queue.size()) + "\n")
			}
		}
	}
	defer wr.Flush()

}
