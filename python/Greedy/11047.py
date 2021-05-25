import sys
sys.setrecursionlimit(2500)
LMIT = 100001
dp = [[0] * LMIT for _ in range(102)]


if __name__ == "__main__":
    n, k = map(int, input().split())
    m = []
    num = 0
    for i in range(n):
        m.append(int(input()))
    for i in range(n - 1, -1, -1):
        if k == 0:
            break
        if m[i] > k:
            continue
        num += k // m[i]
        k %= m[i]
    print(num)
