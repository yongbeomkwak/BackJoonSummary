import sys


if __name__ == "__main__":
    N, M = map(int, (sys.stdin.readline().rstrip().split()))
    answer = 0
    A = []
    B = []
    C = [[True] * 51 for _ in range(51)]

    for i in range(N):
        A.append(sys.stdin.readline().rstrip())
    for i in range(N):
        B.append(sys.stdin.readline().rstrip())
        for j in range(M):
            if(A[i][j] != B[i][j]):
                C[i][j] = False

    if(N < 3 or M < 3):
        for i in range(N):
            for j in range(M):
                if(not C[i][j]):
                    answer = -1
                    break
        print(answer)
    else:
        for i in range(N-2):
            for j in range(M-2):
                if(not C[i][j]):
                    answer += 1
                    for p in range(i, i+3):
                        for q in range(j, j+3):
                            C[p][q] = not C[p][q]  # 뒤집기

        for i in range(N):
            for j in range(M):
                if(not C[i][j]):
                    answer = -1
                    break
        print(answer)
