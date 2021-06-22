package main

import (
	"bufio"
	"container/heap"
	"os"
	"strconv"
	"strings"
)

type PriorityQueue []*Item
type Item struct {
	data int
}

// heap을 사용하기 위해 정의 되야하는 interface들
func (pq PriorityQueue) Len() int {
	return len(pq)
}
func (pq PriorityQueue) Less(i, j int) bool { // 내림찯순 오름차순 정렬 관여
	return pq[i].data < pq[j].data
}
func (pq PriorityQueue) Swap(i, j int) { // Swap
	pq[i], pq[j] = pq[j], pq[i]
}
func (pq *PriorityQueue) Push(x interface{}) {
	item := x.(*Item)
	*pq = append(*pq, item)
}
func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	val := old[n-1]
	old[n-1] = nil
	*pq = old[0 : n-1]
	return val
}

/*
1. (pq PriorityQueue) 를 value receiver 라고 부르고, (pq *PriorityQueue) 를 pointer receiver 라고 부릅니다.

pointer receiver 를 쓰는 경우는 보통 1) receiver 의 크기가 매우 크거나 2) receiver 의 내용을 바꿔야 할 필요가 있을 때, 이렇게 두 경우일 때가 많습니다.

PriorityQueue 타입 본체의 크기는 포인터 1개 + int 2개 = 24 byte 이므로 1번은 큰 메리트가 없습니다.

다만, Push 와 Pop 의 경우 slice 자체의 내용을 수정할 필요가 있기 때문에 pointer receiver 를 사용해야 합니다.



2. interface{} 는 Java 의 Object 타입과 유사합니다. 어떠한 type 의 데이터든 가질 수 있습니다.



3. type assertion 이라고 부릅니다. interface 가 가지고 있는 데이터의 type 이 정말로 *Item 인지 검증하고,

검증에 성공하면 그 이후로는  *Item 과 동일하게 활용할 수 있습니다 (예를 들어 .data 구조체 필드를 읽고쓰기)

검증에 실패하면 런타임 에러를 일으킵니다.


1. PriorityQueue 는 slice type 입니다. slice 를 구조체처럼 생각한다면 (배열의 메모리 주소, length, capacity) 로 이루어져 있습니다.

length 는 "현재"의 데이터 크기, capacity 는 (메모리 재할당 없이) 최대로 커질 수 있는 크기 입니다.

배열의 element 는 Item 을 가리키는 포인터이고, Item 은 int 하나를 가지고 있지만, slice "구조체"의 일부는 아닙니다.



2. item = new(Item); item.data = conv_temp; 라고 생각하시면 됩니다.

즉, Item 을 동적 할당 하고, 정해진 field 를 초기화 한 다음에, 동적 할당한 메모리 주소를 item 변수에 넣습니다.
*/
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
	answer := 0
	pq := make(PriorityQueue, 0)
	heap.Init(&pq)
	for i := 0; i < N; i++ {
		temp, _ := r.ReadString('\n')
		temp = strings.TrimSpace(temp) //뒤에 \n제거
		conv_temp, _ := strconv.Atoi(temp)
		item := &Item{data: conv_temp}
		heap.Push(&pq, item)
	}
	for pq.Len() != 1 {
		temp1 := heap.Pop(&pq).(*Item).data
		temp2 := heap.Pop(&pq).(*Item).data
		answer += (temp1 + temp2)
		item := &Item{data: (temp1 + temp2)}
		heap.Push(&pq, item)
	}

	wr.WriteString(strconv.Itoa(answer))
	defer wr.Flush()
}
