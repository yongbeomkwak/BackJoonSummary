import sys
from collections import deque


if __name__ == "__main__":
    N = int(sys.stdin.readline().rstrip())
    q = deque()

    for _ in range(N):
        input_split = sys.stdin.readline().rstrip().split()

        order = input_split[0]

        if order == "push":
            q.appendleft(input_split[1])
        elif order == "pop":
            if q:
                print(q.pop())
            else:
                print(-1)
        elif order == "size":
            print(len(q))
        elif order == "empty":
            if q:
                print(0)
            else:
                print(1)
        elif order == "front":
            if q:
                print(q[-1])
            else:
                print(-1)
        elif order == "back":
            if q:
                print(q[0])
            else:
                print(-1)
