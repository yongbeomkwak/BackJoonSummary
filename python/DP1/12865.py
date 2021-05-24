import sys
sys.setrecursionlimit(2500)
LMIT = 100001
dp = [[0] * LMIT for _ in range(102)]


if __name__ == "__main__":
    item_list = [[0]*2 for _ in range(102)]
    n, K = map(int, input().split())

    for i in range(1, n+1):
        item_list[i][0], item_list[i][1] = map(int, input().split())

    for i in range(1, n+1):
        W = item_list[i][0]
        val = item_list[i][1]
        for j in range(K+1):
            if (j<W):
                dp[i][j]=dp[i-1][j]
            else:
                dp[i][j]=max(dp[i-1][j-W]+val,dp[i-1][j])
    print(dp[n][K])
