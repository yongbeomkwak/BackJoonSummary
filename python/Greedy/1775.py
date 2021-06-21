import sys
from queue import PriorityQueue
if __name__ == "__main__":
    N = int(sys.stdin.readline().rstrip())
    answer = 0
    pq = PriorityQueue()
    for _ in range(N):
        pq.put(int(sys.stdin.readline().rsplit()[0]))

    while(pq.qsize()!=1):
        temp1=pq.get()
        temp2=pq.get()
        answer+=temp1+temp2
        pq.put(temp1+temp2)
    print(answer)