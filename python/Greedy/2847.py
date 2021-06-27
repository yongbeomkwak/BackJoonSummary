import sys


if __name__ == "__main__":
    N = int(sys.stdin.readline().rstrip())
    arr = []
    for _ in range(N):
        arr.append(int(sys.stdin.readline().rstrip()))

    answer = 0
    for i in range(N-1, 0, -1):
        temp1 = arr[i]
        temp2 = arr[i-1]
        if(temp2 >= temp1):
            answer += (temp2-(temp1-1))
            arr[i-1] = temp1-1
    print(answer)
