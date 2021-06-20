import sys

if __name__ == "__main__":
    T = int(sys.stdin.readline().rstrip())
    for _ in range(T):
        result = 0
        N = int(sys.stdin.readline().rstrip())
        _score = [[] for i in range(N)]
        for i in range(N):
            P = sys.stdin.readline().rstrip().split()
            _score[i].append(int(P[0]))
            _score[i].append(int(P[1]))
        _sorted_score = sorted(_score, key=lambda x: x[0])

        _min = _sorted_score[0][1]
        for i in range(len(_sorted_score)):
            if(_min >= _sorted_score[i][1]):
                _min = _sorted_score[i][1]
                result += 1
        print(result)
